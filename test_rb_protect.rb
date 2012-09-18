$LOAD_PATH << "."
require 'libprotect'
prot = Protect.new
prot.do_protect

GC.start
