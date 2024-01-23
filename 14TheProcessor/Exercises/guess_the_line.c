

#define PRAGMA(x) _Pragma(#x) 
#define IDENT(x) PRAGMA(ident #x)



int main (void)
{
    // What will the following line look like after macro expansion
    IDENT(foo)

    //IDENT(foo) -> PRAGMA(ident foo) -> _Pragma("ident foo")
    // --> destringize -- > ident foo
    return 0;
}