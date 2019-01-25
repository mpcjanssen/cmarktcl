load cmake-build-debug/libcmarktcl.dylib

puts [cmark::markdowntohtml "## abcd\n\n* test"]
cmark::markdowntohtml
