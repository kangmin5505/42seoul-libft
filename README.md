# 42seoul-libft
42seoul libft project

## Common Instructions
- Norm
- No error(segmentation fault, bus error, double free, etc)
- No leak
- Submit Makefile which will compile your source files
  - Flags -Wall, -Wextra and -Werror
  - Use cc(compiler)
  - No relink
  - Least contain $(NAME), all, clean, fclean, re
- To turn in bonuses to your project, you must include a rule bonus to your Makefile,
which will add all the various headers, librairies or functions that are forbidden on
the main part of the project. Bonuses must be in a different file _bonus.{c/h}.
- If your project allows you to use your libft, you must copy its sources and its
associated Makefile in a libft folder with its associated Makefile. Your project’s
Makefile must compile the library by using its Makefile, then compile the project.

## Mandatory part
![image](https://user-images.githubusercontent.com/74703501/141422475-0992d3ff-ae1c-46f8-9e70-35f4eeda5ed1.png)
### Technical considerations
- Don't use global variables
- Subfunction must be static to avoid publishing them with your library.
- Submit all files in the root of your repository.
- Don't submit unused files.
- Every .c mush compile with flags.
- Must use the command 'ar' to create your library.

### Part 1 - Libc functions
- Must be prefixed by "ft_".
- Don't use "restrict" qualifier.
- Prototype
```c
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
size_t  ft_strlen(const char *s);
void    *ft_memset(void *s, int c, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
int     ft_toupper(int c);
int     ft_tolower(int c);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char    *ft_strnstr(const char *big, const char *little, size_t len);
int     ft_atoi(const char *nptr);
```

- Impliement
```c
int ft_isalpha(int c)
{
  // 호환성과 효율성을 위해 부호 x(unsigned)
  // 대문자의 경우 '| 32'를 통해 소문자로 변경
  return (((unsigned)c | 32) - 'a' < 26);
}
```
```c
int ft_isdigit(int c)
{
  // 호환성과 효율성을 위해 부호 x(unsigned)
  return ((unsigned)c - '0' < 10);
}
```
```c
#include "libft.h"

int ft_isalnum(int c)
{
  return (ft_isalpha(c) || ft_isdigit(c));  
}
```
```c
int ft_isascii(int c)
{
  // c가 7 bits unsigned char로 표현할 수 있는 값인 지 확인하는 함수
  // 7 bits로 표현(0x7f)할 수 없는 범위 표현한 것을 & 연산자를 통해 확인
  // 만약 0 이외의 수가 나오면 is not ascii
  return (!(c & ~0x7f));
}
```
```c
int ft_isprint(int c)
{
  // 출력 가능한지 확인하는 함수
  // c에서 스페이스(0x20)이상이면서 127(0x5f + 0x20)미만인 것
  return ((unsigned)c - 0x20 < 0x5f);
  
}
```
```c
size_t  ft_strlen(const char *s)
{
  // 주소의 차이를 통해 길이를 구함
  const char  *a;
  
  a = s;
  while (*a)
    a++;
  return (a - s);
}
```
```c
void  *ft_memset(void *s, int c, size_t n)
{
  // pointer가 가리키는 메모리에 n bytes를 1 byte씩 접근하여 c로 채워주는 함수
  // 1 byte씩 접근하기 위해서는 unsigned char를 사용하는 것이 관례
  // signed char는 1 byte씩 접근한다는 보장이 없음
  unsigned char *temp;
  size_t         idx;
  
  temp = (unsigned char *)s;
  idx = 0;
  while (idx++ < n)
    *temp++ = (unsigned char)c;
  return (s);
}
```
```c
#include "libft.h"

void  ft_bzero(void *s, size_t n)
{
  // pointer가 가리키는 메모리에 n bytes를 1 byte씩 접근하여 0로 채워주는 함수
  ft_memset(s, 0, n);
}
```
```c
void  *ft_memcpy(void *dest, const void *src, size_t n)
{
  // src로부터 dest에 n bytes 복사하는 함수
  // the memory areas must not overlap.
  size_t              idx;
  unsigned char       *d;
  const unsigned char *s;
  
  idx = 0;
  d = (unsigned char *)dest;
  s = (const unsigned char *)src;
  while (idx++ < n)
    *d++ = *s++;
  return (d);
}
```
```c
void  *ft_memmove(void *dest, const void *src, size_t n)
{
  // src로부터 dest에 n bytes 복사하는 함수
  // the memory areas may overlap.
  // 문서에는 signed char임 => 왜??
  unsigned char        *d;
  const unsigned char  *s;
  
  d = (unsigned char *)dest;
  s = (const unsigned char *)src;
  if (d == s)
    return (dest);
  if (d >= s)
  {
    while(n--)
      *d++ = *s++;
  }
  else
  {
    while(n--)
      d[n] = s[n];
  }
  return (dest);
}
```
