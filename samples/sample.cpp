// Reloaded C/C++ Sample.
#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>

#if !defined(RELOADED) && defined(__amd64__) // Target-specific macros supported.
# define ALL_UPPERCASED_IF_CONST_OR_MACRO 2
#endif --invalid_token_after_endif           // Comment is fine...

#define MY_API
#define MY_INLINE inline __attribute__((always_inline))
#define MY_LIKELY(...) __builtin_expect(!!(__VA_ARGS__), 1)

#define SUCCEEDED(...) ((__VA_ARGS__) == 0)
#define FAILED(...) ((__VA_ARGS__) != 0)

namespace sample {

/* Markdown code sections like `SampleClass` are recognized. */
class SampleClass {
public:
  inline SampleClass() noexcept : _a(0.1), _b(false) {}
  MY_INLINE uint8_t asUInt8() noexcept { return static_cast<uint8_t>(_a) + _b; }
  virtual uint8_t virtualMethod() noexcept = 0;

  double _a;
  bool _b;
};

// Doxygen commands like \brief and @param x are recognized as well.
class DerivedClass : public SampleClass {
public:
  MY_API uint8_t virtualMethod() noexcept override { return this->asUInt8(); };
  __attribute__((__visibility__("hidden"))) void test();
};
void DerivedClass::test() {}

// Constants starting with `k` prefix are recognized and highlighted.
//
// TODO: Common patterns as TODO|FIXME|HACK|ERROR|WARNING|FATAL are highlighted.
// TODO(some-person): Some projects use assignment inside TODO(...) as well.
enum SampleEnum {
  kErrorOk = 0,
  kErrorSomething = 1,
  ERROR_OK = 0,
  ERROR_SOMETHING = 2,
  kSomeValue = 3,
  UPPERCASED_VALUE = 4
};

// Numeric value suffix uses slightly different shade than the number itself.
static const unsigned int binConst = 0b01010101'00110011'00001111'00000000u;
static const unsigned long hexConst = 0x12345678UL;

// ---------------------------------------------------------------
// [Sample code that shows some extra features compared to others]
// ---------------------------------------------------------------

static void sampleFunc(int x) { assert(x >= 0); }
static void sampleLikely(int x) { if (MY_LIKELY(x)) sampleFunc(x); }
static bool sampleTernary(int x) { return x ? true : false; }
static bool sampleStatus(int x) { return SUCCEEDED(x) || FAILED(x); }
static bool sampleSuccess(int x) { return x == kErrorOk && x == ERROR_OK; }
static bool sampleFailure(int x) { return x == ENOMEM || x == kErrorSomething || x == ERROR_SOMETHING; }
static void sampleSignal() { raise(SIGKILL + SIGUNKNOWN); }

static bool sampleAnything(int x) { return x != kSomeValue; }
static int sampleAllUpper() { return UPPERCASED_VALUE; }
static void sampleFormat(FILE* file = stdout) { ::fprintf(file, "Reloaded C++ v%d.%d.%5d\n", 0, 0, 1); }
static void samplePthread(pthread_t* thread) { pthread_join(thread, nullptr); }

static SampleClass* sampleNew() { return new(std::nothrow) DerivedClass(); }
static void sampleDelete(SampleClass* obj) { delete obj; }

template<typename T>
static size_t sampleSizeOfT() { return sizeof(T); }

} // sample
