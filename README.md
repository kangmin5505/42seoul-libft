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
void    *ft_memchr(const void *src, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char    *ft_strnstr(const char *big, const char *little, size_t len);
int     ft_atoi(const char *nptr);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strdup(const char *s1);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const *s, char c);
char    *ft_itoa(int n);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
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
#include "libft.h"

size_t  ft_strlen(const char *s)
{
  // 주소의 차이를 통해 길이를 구함
  const char  *a;
  
  a = s;
  while (*a)
    a++;
  return ((size_t)(a - s));
}
```
```c
#include "libft.h"

void  *ft_memset(void *s, int c, size_t n)
{
  // "fill memory with a constant byte"
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
#include "libft.h"

void  *ft_memcpy(void *dest, const void *src, size_t n)
{
  // "copy memory area"
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
  return (dest);
}
```
```c
void  *ft_memmove(void *dest, const void *src, size_t n)
{
  // "copy memory area"
  // src로부터 dest에 n bytes 복사하는 함수
  // the memory areas may overlap.
  // 문서에는 signed char임 => 왜??
  unsigned char        *d;
  const unsigned char  *s;
  
  if (dest == src)
    return (dest);
  else if (dest < src)
    dest = ft_memcpy(dest, src, n);
  else
  {
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    while (n)
    {
      d[n] = s[n];
      n--;
    }
  }
  return (dest);
}
```
```c
#include "libft.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
  // 복사하려는 문자열의 길이를 반환(return the total length of the string they tried to create.)
  size_t  src_len;
  size_t  idx;
  
  src_len = ft_strlen(src);
  idx = 0;
  if (!(*dest || *src))
    return (0);
  while (idx < src_len && idx + 1 < size)
  {
    dest[idx] = src[idx];
    idx++;
  }
  dest[idx] = '\0';
  return (src_len);
}
```
```c
#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t size)
{
  //이으려고 하는 총 문자열의 길이를 반환(return the total length of the string they tried to create.)
  size_t  dest_len;
  size_t  src_len;
  size_t  idx;
  
  dest_len = ft_strlen(dest);
  src_len = ft_strlen(src);
  if (dest_len <= size)
    return (src_len + size);
  while (dest[dest_len + idx] && (dest_len + idx + 1) < size)
  {
    dest[dest_len + idx] = src[idx];
    idx++;
  }
  dest[dest_len + idx] = '\0';
  return (dest_len + src_len);
  
}
```
```c
static int  ft_islower(int c)
{
  return ((unsigned)c - 'a' < 26);
}

int ft_toupper(int c)
{
  if (ft_islower(c))
    return (c & 0x5f);
  return (c);
}
```
```c
static int  ft_isupper(int c)
{
  return ((unsigned)c - 'A' < 26);
}

int ft_tolower(int c)
{
  if (ft_isupper(c))
    return (c | 32);
  return (c);
}
```
```c
char  *ft_strchr(const char *s, int c)
{
  // "locate character in string"
  // return a pointer to the first occurrence of the character c in the string s.
  // return NULL if the not found.
  // the terminating null byte is considered part of the string.
  char  find;
  char  *ret;
  
  find = (char)c;
  ret = (char *)s;
  while (*ret)
  {
    if (*ret == find)
      return (ret)
    ret++;
  }
  if (*ret == find)
    return (ret);
  return (0);
}
```
```c
#include "libft.h"

char  *ft_strrchr(const char *s, int c)
{
  // "locate character in string"
  // return a pointer to the last occurrence of the character c in the string s.
  // return NULL if the not found.
  // the terminating null byte is considered part of the string.
  int         s_len;
  char        find;
  const char  *ret;
  
  s_len = ft_strlen(s);
  find = (char)c;
  ret = &s[s_len];
  while (s_len)
  {
    if (ret[s_len] == find)
      return (&ret[s_len]);
    s_len--;
  }
  if (ret[s_len] == find)
    return (&ret[s_len]);
  return (0);
}
```
```c
#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
  // "compare two strings"
  // return an integer less than, equal to, or greater than zero if s1 is found,
  // respectively, to be less than, to match, or be greater than s2.
  const char *ptr1;
  const char *ptr2;

  ptr1 = (const char *)s1;
  ptr2 = (const char *)s2;
  while (n--)
  {
    if (*ptr1 != *ptr2)
      return ((int)(*ptr1 - *ptr2));
    ptr1++;
    ptr2++;
  }
  return (0);
}
```
```c
#include "libft.h"

void  *ft_memchr(const void *src, int c, size_t n)
{
  // "scan memory for a character"
  // both c and the bytes of the memory area pointed to by s are interpreted as 'unsigend char'.
  // return a pointer to the matching byte or NULL if the character does not occur in the given memory area.
  const unsigned char *s;
  
  s = (const unsigned char *)src;
  c = (unsigned char)c;
  while (n--)
  {
    if (*s == c)
      return ((void *)s);
    s++;
  }
  return (0);
}
```
```c
#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
  // "compare memory areas"
  // compares the first n bytes (each interpreted as 'unsigned char') of the meory areas s1 and s2.
  // return an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than first n bytes of s2.
  // for a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes (interpreted as 'unsigned char') that differ in s1 and s2.
  // if n is zero, the return value is zero.
  const unsigned char *ptr1;
  const unsigned char *ptr2;
  
  ptr1 = (const unsigned char *)s1;
  ptr2 = (const unsigned char *)s2;
  while (n--)
  {
    if (*ptr1 != *ptr2)
      return ((int)(*ptr1 - *ptr2));
    ptr1++;
    ptr2++;
  }
  return (0);
}
```
```c
#include "libft.h"

char  *ft_strnstr(const char *str, const char *substr, size_t len)
{
  // "locate a substring in a string"
  // locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len characters are searched.
  size_t      substr_len;
  const char  *s;
  
  if (*substr == '\0')
    return ((char *)str);
  substr_len = ft_strlen(substr);
  s = (const char *)str;
  while (*s && substr_len < len--)
  {
    if (ft_memcmp(s, substr, substr_len) == 0)
      return ((char *)s);
    s++;
  }
  return (0);
}
```
```c
#include "libft.h"

int ft_isspace(int c)
{
  // '\t'이 (unsigned)c보다 클 경우 underflow 발생
  return (c == ' ' || (unsigned)c - '\t' < 5);
}

int ft_atoi(const char *nptr)
{
  // "convert a string to an integer"
  // convert the initial portion of the string pointed to by nptr to int.
  // return converted value
  // compute n as a negative number to avoid overflow on INT_MIN
  int        n;
  int        neg;
  const char *s;
  
  n = 0;
  neg = -1;
  s = nptr;
  while (ft_isspace(*s))
    s++;
  if (*s == '+')
    s++;
  else if (*s == '-')
  {
    neg = 1;
    s++;
  }
  while (ft_isdigit(*s))
    n = 10 * n - (*s++ - '0');
  return (neg * n);
}
```
```c
#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
  // "memory allocation"
  // contiguously allocates enough space for count objects that are size bytes of memory each and returns a pointer to the allocated memory. => contiguously??
  // is filled with bytes of value zero.
  void  *mem;
  
  if (!(mem = malloc(count  * size)))
    return (0);
  ft_memset(mem, 0, (count * size));
  return (mem);
}
```
```c
#include "libft.h"

char  *ft_strdup(const char *s1)
{
  // "save a copy of a string"
  // allocate sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.
  // If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
  // => what is "errno is set to ENOMEM"?
  size_t  s_len;
  char    *mem;
  size_t  idx;
  
  s_len = ft_strlen(s1);
  mem = (char *)malloc(s_len * sizeof(char));
  if (!mem)
    return (0);
  idx = 0;
  while (*s1)
  {
    mem[idx] = s1[idx];
    idx++;
  }
  mem[idx] = '\0';
  return (mem);
}
```
```c
#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
  // "Allocates and returns a substring from the string 's'. The substring begins at index 'start' and is of maximum size 'len'"
  // s : the string from which to create the substring
  // start : the start index of the substring in the string 's'
  // len :the maximum length of the substring
  // return value : the substring. NULL if the allocation fails
  // 예외처리 : s가 NULL일 때, start가 s의 길이보다 길 때, start 인덱스부터의 s의 길이가 len 보다 작을 때, 메모리 할당 못 받았을 때
  // 사용함수 : ft_strlcpy
  unsigned int  s_len;
  size_t        new_len;
  char          *substr;
  
  s_len = (unsigned int)ft_strlen(s);
  if (!s || (s_len < start))
    return (NULL);
  new_len = ft_strlen(s + start);
  if (new_len < len)
    len = new_len;
  substr = (char *)malloc((len + 1) * sizeof(char));
  if (!substr)
    return (NULL);
  ft_strlcpy(substr, s + start, len + 1);
  return (substr);
}
```
```c
#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
  //"Allocates and returns a new string, which is the result of the concatenation of 's1' and 's2'"
  // s1 : the prefix string
  // s2 : the suffix string
  // return value : the new string. NULL if the allocation fails
  // 예외처리 : s1와 s2가 모두 없는 경우 NULL, 둘(s1, s2) 중 하나만 있는 경우 ft_strdup, 메모리 할당 못 받았을 때
  // 사용함수 : ft_strdup, ft_strlen, ft_strlcpy, ft_strlcat
  char    *ret_str;
  size_t  s1_len;
  size_t  s2_len;
  
  if (!s1 && !s2)
    return (NULL);
  else if (!s1 || !s2)
  {
    if (!s1)
      return (ft_strdup(s2));
    else
      return (ft_strdup(s1));
  }
  s1_len = ft_strlen(s1);
  s2_len = ft_strlen(s2);
  ret_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
  if (!new_str)
    return (NULL);
  ft_strlcpy(ret_str, s1, s1_len + 1);
  ft_strlcat(ret_str, s2, s1_len + s2_len + 1);
  return (ret_str);
}
```
```c
static size_t ft_get_start_idx(const char const *s1, const char const *set)
{
  size_t  s1_len;
  size_t  idx;
  
  s1_len = ft_strlen(s1);
  idx = 0;
  while (idx < s1_len)
  {
    if (ft_strchr(set, s1[idx]) == 0)
      break ;
    idx++;
  }
  return (idx);
}

static size_t ft_get_end_idx(const char const *s1, const char const *set)
{
  size_t  s1_len;
  size_t  idx;
  
  s1_len = ft_strlen(s1);
  idx = 0;
  while (idx < s1_len)
  {
    if (ft_strchr(set, s1[s1_len - idx - 1]) == 0)
      break ;
    idx++;
  }
  return (s1_len - idx);
}

char    *ft_strtrim(char const *s1, char const *set)
{
  // "Allocates and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string"
  // s1 : the string toe be trimmed
  // s2 : the reference set of characters to trim
  // return value : the trimmed string. NULL if the allocation fails
  // 예외처리 : s1이 NULL인 경우, set이 NULL인 경우, 메모리 할당을 못 받았을 경우
  // 사용함수 : ft_strdup, ft_strchr, ft_strrchr, ft_strlen
  char    *ret_str;
  size_t  start_idx;
  size_t  end_idx;
  
  if (!s1)
    return (NULL);
  else if (!set)
    return (ft_strdup(s1));
  start_idx = ft_get_start_idx(s1, set);
  end_idx = ft_get_end_idx(s1, set);
  ret_str = (char *)malloc(sizeof(char) * (end_idx - start_idx + 1));
  if (!ret_str)
    return (NULL);
  ft_strlcpy(ret_str, s1 + start_idx, end_idx - start_idx + 1);
  return (ret_str);
}
```
```c
#include "libft.h"

static int  ft_is_delimiter(char c, char delimiter)
{
  return (c == delimiter);
}

static size_t ft_get_word_cnt(char const *s, char c)
{
  size_t  word_cnt;
  size_t  idx;
  size_t  s_len;
  
  word_cnt = 0;
  idx = 0;
  s_len = ft_strlen(s);
  while (idx < s_len)
  {
    if (ft_is_delimiter(s[idx], c) != 1)
    {
      word_cnt++;
      idx++;
      while (s[idx] && (ft_is_delimiter(s[idx], c) != 1))
        idx++;
      idx--;
    }
    idx++;
  }
  return (word_cnt);
}

static char  **ft_malloc_error(char **strs)
{
  size_t  idx;
  
  idx = 0;
  while (strs[idx])
  {
    free(strs[idx]);
    idx++;
  }
  free(strs);
  return (0);
}

static char  **ft_get_split_str(char **strs, char const *s, size_t word_cnt, char c)
{
  char const  *s1;
  char const  *temp;
  size_t      s_idx;
  
  s1 = s;
  s_idx = 0;
  while (s_idx < word_cnt)
  {
    if (is_delimiter(*s1, c) != 1)
    {
      temp = s1;
      while (*s1 && is_delimiter(*s1, c) != 1)
        s1++;
      strs[s_idx] = (char *)malloc(sizeof(char) * (s1 - temp + 1));
      if (!strs[s_idx])
        return (ft_malloc_error(strs));
      ft_strlcpy(strs[s_idx], temp, s1 - temp + 1);
      s_idx++;
    }
    s1++;
  }
  strs[s_idx] = '\0';
  return (strs);
}

char    **ft_split(char const *s, char c)
{
  // "Allocates and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. The array must be ended by a NULL pointer"
  // s : the stinrg to be split
  // c : the delimiter character
  // return value : the array of new strings resulting from the split. NULL if the allocation fails
  // 예외처리 : s가 NULL일 때, 메모리 할당 못 받았을 때
  char          **strs;
  size_t       word_cnt;
  
  if (!s)
    return (0);
  word_cnt = ft_get_word_cnt(s, c);
  strs = (char **)malloc(sizeof(char *) * (word_cnt + 1));
  if (!strs)
    return (0);
  strs = ft_get_split_str(strs, s, word_cnt, c);
  if (!strs)
    return (0);
  return (strs);
}
```
```c
#include "libft.h"

static size_t ft_int_len(long long nbr, unsigned int neg)
{
  unsigned int  len;
  
  if (nbr == 0)
    return (1);
  len = 0;
  while (nbr > 0)
  {
    nbr /= 10;
    len++;
  }
  return (len + neg);
}

char    *ft_itoa(int n)
{
  // "Allocates and returns a string representing the integer received as an argument. Negative numbers must be handled"
  // n : the integer to convert
  // return value : the string representing the integer. NULL if the allocation fails
  long long     nbr;
  unsigned int  neg;
  unsigned int  len;
  char          *str;
  
  nbr = (long long)n;
  neg = 0;
  if (nbr < 0)
  {
    nbr *= -1;
    neg = 1;
  }
  len = ft_int_len(nbr, neg);
  str = (char *)malloc(sizeof(char) * (len + 1));
  if (!str)
    return (0);
  str[len] = '\0';
  while (--len >= 0)
  {
    str[len] = '0' + (nbr % 10);
    nbr /= 10;
  }
  if (neg == 1)
    str[0] = '-';
  return (str);
}
```
```c
#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  // "Applies the function 'f' to each character of the string 's', and passing its index as first argument to create a new string resulting from successive applications of 'f'"
  // s : the string on which to iterate
  // f : the function to apply to each character
  // return value : the string created from the successive applications of 'f'. Returns NULL if the allocation fails
  // 예외처리 : s가 NULL일 때, f가 NULL일 때
  unsigned int  len;
  char          *ret_str;
  unsigned int  idx;
  
  if (!s || !f)
    return (0);
  len = ft_strlen(s);
  ret_str = (char *)malloc(sizeof(char) * (len + 1));
  if (!ret_str)
    return (0);
  idx = 0;
  while (s[idx])
  {
    ret_str[idx] = (*f)(idx, s[idx]);
    idx++;
  }
  ret_str[idx] = '\0';
  return (ret_str); 
}
```
```c
#include "libft.h"
void    ft_striteri(char *s, void (*f)(unsigned int, char *))
{
  // "Applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessay"
  // s : the string on which to iterate
  // f : the function to apply to each character
  // return value : None
  unsigned int  idx;
  unsigned int  s_len;
  
  if (!s || !f)
    return (0);
  s_len = ft_strlen(s);
  idx = 0;
  while (idx < s_len)
  {
    (*f)(idx, &s[idx]);
    idx++;
  }
}
```
```c
#include "libft.h"

void    ft_putchar_fd(char c, int fd)
{
  // "Outputs the character 'c' to the given file descriptor"
  // c : the character to output
  // fd : the file descriptor on which to write
  // file descriptor : 프로세스에서 특정 파일에 접근할 때 사용하는 추상적인 값(파일의 인덱스??)
  // return value : None
  if (fd >= 0)
    write(fd, &c, 1);
}
```
```c
#include "libft.h"

void    ft_putstr_fd(char *s, int fd)
{
  // "Outputs the string 's' to the given file descriptor"
  // s : the string to output
  // fd : the file descriptor on which to write
  // return value : None
  if (s || (fd >= 0))
    write(fd, s, ft_strlen(s));
}
```
```c
#include "libft.h"

void    ft_putendl_fd(char *s, int fd)
{
  // "Outputs the string 's' to the given file descriptor, followed by a newline"
  // s : the string to output
  // fd : the file descriptor on which to write
  if (s || (fd >= 0))
  {
    write(fd, s, ft_strlen(s));
    write(fd, "\n", 1);
  }
}
```
```c
#include "libft.h"

static void ft_print_screen(long long nbr, int fd)
{
  char  c;
  
  if (nbr >= 10)
  {
    ft_print_screen(nbr / 10, fd);
  }
  c = nbr % 10 + '0'
  write(fd, &c, 1);
}

void    ft_putnbr_fd(int n, int fd)
{
  // "Outputs the integer 'n' to the given file descriptor"
  // n : the integer to output
  // fd : the file descriptor on which to write
  // return value : None
  
  long long nbr;
  
  nbr = (long long)n;
  if (fd >= 0)
  {
    if (nbr < 0)
    {
      nbr *= -1;
      write(fd, "-", 1);
    }
    ft_print_screen(nbr, fd);
  }
}
