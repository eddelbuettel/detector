
#include <Rcpp/Lightest>

#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif

//' @title detector
//'
//' @description Store a number of different compile-time \code{#define} values
//' and return them in a named character vector.
//'
//' @return A named character vector.
//' @useDynLib detector, .registration=TRUE
//' @importFrom Rcpp evalCpp
//' @export
// [[Rcpp::export]]
Rcpp::CharacterVector detector() {
  Rcpp::CharacterVector v(10);

#if defined(__APPLE__)
  v[0] = "set";

  #if TARGET_OS_OSX
  v[1] = "set";
  #endif

  #if TARGET_CPU_ARM64
  v[2] = "set";
  #endif

  #if TARGET_CPU_X86_64
  v[3] = "set";
  #endif

#endif

#if defined(__MACH__)
  v[4] = "set";
#endif

#if defined(__x86_64__)
  v[5] = "set";
#endif

#if defined(__linux__)
  v[6] = "set";
#endif

#if defined(__GLIBC__)
  v[7] = "set";
#endif

#if defined(__clang__)
  v[8] = "set";
#endif

  v[9] = std::to_string(__cplusplus);

  v.names() = Rcpp::CharacterVector::create("Apple", "Apple_OS_X", "Apple_ARM64", "Apple_X86_64",
                                            "MACH", "X86_64", "Linux", "Glibc", "clang", "C++");

  return v;
}
