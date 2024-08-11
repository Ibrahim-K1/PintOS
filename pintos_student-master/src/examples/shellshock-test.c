#include <stdio.h>


// char shellcode[] =
//   "\x90\x90\x90\x90\x90\xe9\x0b\x00"
//   "\x00\x00\x6a\x02\xcd\x30\x31\xc0"
//   "\x50\x40\x50\xcd\x30\xe8\xf0\xff"
//   "\xff\xff""crack";

//the below code has the payload for the create attack, this works as, we have pushed null into the stack then we pushed our string which has a hex
//code that contains the payload called cats, when this is pushed into the stack the appropriate system call is called, after that is pushed we then
unsigned char code[]="\x6A\x00\x68\x73\x74\x61\x63\x89\xE2\x6A\x05\x52\x6A\x04\xCD\x30";
// unsigned char code[]="\x6A\x00\x68\x73\x74\x61\x63\x89\xE2\x68\xA4\x01\x00\x00\x52\x6A\x04\xCD\x30";

int main( void )
{
int (*ret)() =(int(*)())code;
  ret();
  //exit(0);

  /* Assembler code to do the following:
   *
   *  exec("crack");
   *  exit();
   *
   * Apparently the code 0x01 can not be sent as input to pintos, so
   * it can not be part of any instruction. Reason unknown. Theory:
   * 0x01 may be grabbed as Ctrl-a by QEMU ?
   *
   * Translate push 0x01 ==> ... push %eax
   *
   * The tricky part is to figure out at which address the name of the
   * program to start is stored. The call instruction solves it
   * nicely. It saves the following address as return address.
   */

/*
//   __asm__("jmp    0x0f;"             /* jump to CALL */
// /* actual address of string pushed as return address by CALL */
//           "push   $0x4;"             /* push EXEC syscall number */
//           "int    $0x30;"            /* make syscall */
//           "xor    %eax,%eax;"        /* load 0 in eax */
//           "push   %eax;"             /* push exit_status */
//           "inc    %eax;"             /* inc eax to 1 */
//           "push   %eax;"             /* push EXIT syscall number */
//           "int    $0x30;"/* make syscall */
// /* CALL */"call   -0x0C;"            /* jumps back again */
//           ".string \"crack\";"       /* program to start */
//     );

//


// __asm__("jmp   l2; "
//         "l1: mov eax, [esp+16]"
//         "push %eax;"
//         "int $0x30;"
//         "xor %eax,%eax;"
//         "push %eax;"
//         "inc %eax;"
//         "push %eax;"
//         "int $0x30;"
//         "l2: call l1;"
// );
// exit(0);
}


//hi
// jmp   0x11;
// mov eax, [esp+16];
// mov edx, [esp+12];
// push %eax;
// push %edx;
// int $0x30;
// xor %eax,%eax;
// push %eax;
// inc %eax;
// push %eax;
// int $0x30;
// call 0xDE;