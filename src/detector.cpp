
#include <Rcpp/Lightest>

#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif

//' @title detector
//'
//' @description Store a number of different compile-time \code{#define} values
//' and returns them in a named character vector.
//'
//' @return A named logical vector.
//' @useDynLib detector, .registration=TRUE
//' @importFrom Rcpp evalCpp
//' @export
// [[Rcpp::export]]
Rcpp::LogicalVector detector() {
  Rcpp::LogicalVector v(9);  // defaults to all zeros, ie all FALSE

#if defined(__APPLE__)
  v[0] = TRUE;

  #if TARGET_OS_OSX
  v[1] = TRUE;
  #endif

  #if TARGET_CPU_ARM64
  v[2] = TRUE;
  #endif

  #if TARGET_CPU_X86_64
  v[3] = TRUE;
  #endif

#endif

#if defined(__MACH__)
  v[4] = TRUE;
#endif

#if defined(__x86_64__)
  v[5] = TRUE;
#endif

#if defined(__linux__)
  v[6] = TRUE;
#endif

#if defined(__GLIBC__)
  v[7] = TRUE;
#endif

#if defined(__clang__)
  v[8] = TRUE;
#endif

  v.names() = Rcpp::CharacterVector::create("Apple", "Apple_OS_X", "Apple_ARM64", "Apple_X86_64",
                                            "MACH", "X86_64", "Linux", "Glibc", "clang");

  return v;
}

//' @title versions
//'
//' @description Store the C++ compilation standard and returns it in a named integer vector.
//'
//' @return A named integer vector.
//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector versions() {
  Rcpp::IntegerVector v(1);

  v[0] = __cplusplus;

  v.names() = Rcpp::CharacterVector::create("C++");

  return v;
}
