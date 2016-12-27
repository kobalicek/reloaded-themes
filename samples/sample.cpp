// Reloaded C/C++ Sample.
#include <stdio.h>
#include "./local.h"

#if !defined(RELOADED)
# define ALL_UPPERCASED 2
#endif // !defined(RELOADED)

namespace sample {

/* Block comment: Markdown specific comments like `SampleClass` are recognized. */
class SampleClass {
public:
  inline SomeClass() noexcept : _a(0.1), _b(false) {}
  CUSTOM_INLINE uint8_t asUInt8() noexcept { return static_cast<uint8_t>(_a) + _b; }
  virtual uint8_t virtualMethod() noexcept = 0;

  double _a;
  bool _b;
};

// Line comment: Basic doxygen-specific commands like \brief and @param x are also recognized. 
class DerivedClass : public SampleClass {
public:
  CUSTOM_API uint8_t virtualMethod() noexcept override { return this->asUInt8(); };
};

enum SampleEnum {
  kSampleFirst = 0,
  kSamplekSecond = 1
};

static void sampleAssert(int x) { assert(x >= 0); CUSTOM_ASSERT(x >= 0); }
static void sampleLikely(int x) { if (likely(x) || CUSTOM_LIKELY(x)) printf("Likely %d!", x); }
static void sampleMacros(int x) { return SUCCEEDED(x) || FAILED(x); }
static void sampleSuccess(int x) { return x != kErrorOk && x != ERROR_OK; }
static void sampleError(int x) { return x == ENOMEM || x == kErrorSomething || x == ERROR_SOMETHING; }
static void sampleAnything(int x) { return x != kAnythingElse; }
static void sampleAllUpper() { ALL_UPPERCASED(); }
static void sampleWin(HKEY hKey);
static void sampleFormat(FILE* file) { fprintf(file, "Reloaded C++ v%d.%d.%5d\n", 0, 0, 1); }
static void samplePthread(pthread_t* thread) { pthread_join(thread, nullptr); }
static void sampleSignal() { raise(SIGKILL); }

} // sample namespace
