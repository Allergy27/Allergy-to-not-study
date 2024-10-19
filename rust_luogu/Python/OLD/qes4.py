'''
int __cdecl main(int argc, const char **argv, const char **envp)
{
  FILE *v3; // rax
  char Buffer[108]; // [rsp+20h] [rbp-70h] BYREF
  int v6; // [rsp+8Ch] [rbp-4h]

  _main();
  puts(&::Buffer);
  v3 = __iob_func();
  fgets(Buffer, 100, v3);
  v6 = strlen(Buffer);
  if ( v6 > 0 && Buffer[v6 - 1] == 10 )
    Buffer[v6 - 1] = 0;
  encrypt(Buffer);
  if ( !strcmp(Buffer, "eobdxtk3w\\b\\eVmmz\\qfu3qpf~") )
    puts(&byte_40400D);
  else
    puts(&byte_404012);
  puts(&byte_404017);
  while ( getch() != 32 )
    ;
  return 0;
}
'''