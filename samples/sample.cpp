// Reloaded C/C++ Sample.
#include <stdint.h>
#include <stdio.h>

#if !defined(RELOADED) && defined(__amd64__) // Target-specific macros supported.
# define ALL_UPPERCASED_IF_CONST_OR_MACRO 2
#endif --invalid_token_after_endif           // Comment is fine...

#define CUSTOM_API
#define CUSTOM_INLINE inline __attribute__((always_inline))

namespace sample {

/* Markdown code sections like `SampleClass` are recognized. */
class SampleClass {
public:
  inline SampleClass() noexcept : _a(0.1), _b(false) {}
  CUSTOM_INLINE uint8_t asUInt8() noexcept { return static_cast<uint8_t>(_a) + _b; }
  virtual uint8_t virtualMethod() noexcept = 0;

  double _a;
  bool _b;
};

// Doxygen commands like \brief and @param x are recognized as well.
class DerivedClass : public SampleClass {
public:
  CUSTOM_API uint8_t virtualMethod() noexcept override { return this->asUInt8(); };
  __attribute__((__visibility__("hidden"))) void test();
};
void DerivedClass::test() {}

// Constants starting with `k` prefix are recognized and highlighted.
//
// TODO: Common patterns as TODO|FIXME|HACK|ERROR|WARNING|FATAL are highlighted.
// TODO(some-person): Some projects use assignment inside TODO(...) as well.
enum SampleEnum {
  kSampleFirst = 0,
  kSampleSecond = 1
};

// Numeric value suffix uses slightly different shade than the number itself.
static const unsigned int binConst = 0b01010101'00110011'00001111'00000000u;
static const unsigned long hexConst = 0x12345678UL;

// ---------------------------------------------------------------
// [Sample code that shows some extra features compared to others]
// ---------------------------------------------------------------

static void sampleAssert(int x) { assert(x >= 0); CUSTOM_ASSERT(x >= 0); }
static void sampleLikely(int x) { if (likely(x) || CUSTOM_LIKELY(x)) doSomething(); }
static bool sampleTernary(int x) { return x ? true : false; }
static bool sampleStatus(int x) { return SUCCEEDED(x) || FAILED(x); }
static bool sampleSuccess(int x) { return x == kErrorOk && x == ERROR_OK; }
static bool sampleFailure(int x) { return x == ENOMEM || x == kErrorSomething || x == ERROR_SOMETHING; }
static void sampleSignal() { raise(SIGKILL + SIGUNKNOWN); }

static bool sampleAnything(int x) { return x != kAnythingElse; }
static int sampleAllUpper() { return ALL_UPPERCASED_IF_CONST_OR_MACRO; }
static void sampleWin(HKEY hKey);
static void sampleFormat(FILE* file = stdout) { ::fprintf(file, "Reloaded C++ v%d.%d.%5d\n", 0, 0, 1); }
static void samplePthread(pthread_t* thread) { pthread_join(thread, nullptr); }

static SampleClass* sampleNew() { return new(std::nothrow) DerivedClass(); }
static void sampleDelete(SampleClass* obj) { delete obj; }

template<typename T>
static size_t sampleSizeOfT() { return sizeof(T); }

} // sample
