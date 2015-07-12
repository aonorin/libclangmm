#ifndef DIAGNOSTIC_H_
#define DIAGNOSTIC_H_
#include <string>
#include <vector>
#include <clang-c/Index.h>
#include "TranslationUnit.h"

namespace clang {  
  class Diagnostic {
  public:
    class LocationData {
    public:
      unsigned line, column, offset;
    };
    
    Diagnostic(clang::TranslationUnit& tu, CXDiagnostic& clang_diagnostic);
    
    static const std::string get_severity_spelling(unsigned severity);

    unsigned severity;
    std::string severity_spelling;
    std::string spelling;
    std::string path;
    LocationData start_location, end_location;
  };
}

#endif  // DIAGNOSTIC_H_