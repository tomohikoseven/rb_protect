#include <stdio.h>
#include "ruby.h"
#include "ruby/ruby.h"

// クラス
VALUE cProtect;

#define LIMIT (1024 * 1024)
static int count = 0;
static int status = 0;

VALUE
stack( VALUE arg )
{
    VALUE aa;

    if( count < LIMIT )
    {
        count++;
        stack( aa );
    }

    return;
}

VALUE
rb_test_protect( VALUE self )
{
    VALUE arg = Qnil;
    rb_protect( stack, arg, &status );
    return Qnil;
}
void
Init_libprotect()
{
    cProtect = rb_define_class( "Protect", rb_cObject );

    rb_define_method( cProtect, "do_protect", rb_test_protect, 0 );
 
}
