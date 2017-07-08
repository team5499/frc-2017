file(REMOVE_RECURSE
  "CMakeFiles/check"
  "CMakeFiles/check-complete"
  "test/src/check-stamp/check-install"
  "test/src/check-stamp/check-mkdir"
  "test/src/check-stamp/check-download"
  "test/src/check-stamp/check-update"
  "test/src/check-stamp/check-patch"
  "test/src/check-stamp/check-configure"
  "test/src/check-stamp/check-build"
  "test/src/check-stamp/check-test"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/check.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
