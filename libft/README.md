# libft

## Chapter 1 - 소개

매우 유용한 표준 함수들을 사용할 수 없을 때 C 프로그래밍이 매우 지루해질 수 있습니다. 본 프로젝트는 이런 함수들을 다시 쓰고, 그것들을 이해하고, 그 함수들의 사용법을 배울 기회를 제공합니다. 이 라이브러리는 나중에 진행할 C 프로젝트에 도움이 될 것입니다.


본 프로젝트를 통해서, 우리는 여러분이 만든 함수 리스트를 확장할 수 있는 기회를 제공합니다. 시간을 내서 일 년 내내 자신만의 libft를 확장해 보세요.

## Chapter 2 - 일반지침

- 프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 있는 경우, 해당 파일/함수 들은 Norm 검사에 포함되며, Norm error가 있을 시, 0점을 받게 될 것입니다.
- 함수들은 정의되지 않은 행동들과는 별개로 예기치 않게 중단되어서는 안됩니다.(segmetation fault, bus error, double free 등...) 만약 이렇게 중단되면, 여러분의 프로젝트는 작동하지 않는 것으로 여겨지고 평가에서 0점을 받을 것입니다.
- 필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. memory leak은 용납되지 않습니다.
- 해당 과제에서 요구한 경우 Makefile 을 제출해야하며, 해당 Makefile은 문제에서 제시된 결과물을 `-Wall`, `-Wextra`, `-Werror` 플래그과 함께 컴파일해야합니다. Makefile 은 relink 되어서는 안 됩니다.
- Makefile 은 최소한 `$(NAME)`, `all`, `clean`, `fclean`, `re`규칙을 포합해야 합니다.
- 프로젝트에 보너스를 제출하려면, Makefile에 `bonus`규칙을 포함해야하며, 해당 규칙은 프로젝트의 메인 파트에서 금지되었던 모든 다양한 헤더, 라이브러리, 함수들을 Makefile에 추가할 수 있습니다. 보너스는 반드시 `*_bonus.{c/h}`라는 다른 파일에 있어야 합니다. 필수 파트와 보너스 파트는 개별적으로 평가될 것입니다.
- 프로젝트에서 libft 사용이 허가된 경우, 해당 소스들과 연관된 Makefile을 libft폴더에 Makefile과 함께 복사해 넣어두어야 합니다. 프로젝트의 Makerfile은 반드시 libft의 Makefile을 사용하여 컴파일한 다음, 프로젝트 소스를 컴파일해야만 합니다.
- 제출할 필요가 없고 채점되지 않더라도 우리는 여러분이 프로젝트를 위한 테스트프로그램을 만들 것을 권장합니다. 이 프로그램은 여러분의 과제물과 동료들의 과제물을 쉽게 검증할 기회를 제공할 것입니다. 평가하는 동안 이 테스트 프로그램들이 특히 유용하다는 것을 알게 될 것입니다. 평가 중에는 여러분의 테스트 프로그램과 평가받는 동료의 테스트 프로그램들을 자유롭게 사용할 수 있습니다.
- 할당된 git repository에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 채점할 것입니다. Deepthought가 평가를 하게 된다면, 동료평가 이후에 수행됩니다. 만약 Deepthought가 평가 중 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.

## Chapter3 - 필수사항

<table>
  <tr>
    <td>프로그램 이름</td>
    <td>libft.a</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>\*.c, libft.h, Makefile</td>
  </tr>  
  <tr>
    <td>Makefile</td>
    <td>YES</td>
  </tr>
    <tr>
    <td>허용되는 외부 함수</td>
    <td>밑에서 설명</td>
  </tr>
  <tr>
    <td>libft 허용 여부</td>
    <td>해당 안됨</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>여러분의 커리큘럼에 대한 중요한 함수들을 갖고 있는, 라이브러리를 작성하세요.</td>
  </tr>
</table>       

#### 기술적 고려사항들
- 전역변수를 사용하는 것은 금지되어 있습니다.
- 만약 당신이 복잡한 함수를 작성하기 위해 서브함수를 필요로 할 경우, 서브함수를 라이브러리와 함께 배포하지 않도록 static으로 정의해야 합니다. 이러한 습관은 이후 당신이 프로젝트를 하는데 도움이 될 것입니다.
- 모든 파일을 repository의 root위치에 제출하세요.
- 라이브러리를 생성할때는 `ar`명령어를 이용해야 합니다. `libtool` 명령어는 금지됩니다.

#### Part 1 -Libc functions
첫파트에서 당신은 `libc`를 구성하는 함수들을 `man`에 정의되어 있는대로, 다시 코딩해야합니다. 당신의 함수들은 원본 함수들과 같은 프로토타입으로 보여지고 같은 동작을 수행해야 합니다. 당신의 함수들의 이름은 반드시 "ft_"로 시작해야합니다. 예를 들어 `strlen`은 `ft_strlen`이 되어야 합니다.

> 당신이 다시 코딩해야할 일부 함수의 프로토타입은 `restrict`한정자를 사용합니다. 이 키워드는 c99 표준의 부분입니다. 그러므로 이 키워드를 프로토타입에 포함시키는 것과 `-std=c99`플래그를 사용하여 컴파일하는 것은 금지됩니다. 

당신은 밑의 함수들을 다시 코딩해야합니다. 이 함수들은 어떤 외부함수들도 필요하지 않습니다.

- memset
- bzero
- memcpy
- memccpy
- memmove
- memchr
- memcmp
- strlen
- strlcpy
- strlcat
- strchr
- strrchr
- strnstr
- strncmp
- atoi
- isalpha
- isdigit
- isalnum
- isascii
- isprint
- toupper
- tolower


또한 `malloc`을 사용하여 밑의 함수들도 코딩해야합니다.
- calloc
- strdup

#### Part 2 - 부가적인 기능들
두번째 파트에서, 당신은 libc에 포함되지 않거나 다른 형식에 포함된 함수들의 구성을 코딩해야합니다. 이 함수들 중 일부는 Part 1의 함수들을 작성하는데 유용할 수 있습니다.
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_substr</td>
  </tr>
  <tr>
    <td>프로토타입></td>
    <td>char *ft_substr(char const *s, unsigned int start, size_t len);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 하위문자열을 만들 문자열<br/>  
        #2. 문자열`s`에서 하위문자열이 시작되는 인덱스<br/>
        #3. 하위문자열의 최대 길이</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>하위 문자열.<br/>
        할당에 실패할 경우 NULL반환.</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>malloc</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>문자열`s`로부터 하위문자열을 할당하고 반환.<br/>
        하위문자열은 `start`인덱스에서 시작하고 최대 길이는 `len`</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_strjoin</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>char *ft_strjoin(char const *s1, char const *s2);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 앞에 붙을 문자열<br/>
        #2. 뒤에 붙을 문자열</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>새로운 문자열<br/>
        할당에 실패할 경우 NULL 반환.</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>malloc</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>`s1`과 `s2`가 연속되는 새로운 문자열을 할당하고 반환.</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_strtrim</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>char *ft_strtrim(char const *s1, char const *set);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 다듬어질 문자열<br/>
        #2. 제거할 문자들의 집합</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>다듬어진 문자열<br/>
        할당에 실패할 경우 NULL반환.</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>malloc</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>`s1`의 시작과 끝부분에서 `set`에 명시된 문자들을 제거한 문자열의 복사본을 할당하고 반환.</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_split</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>char **ft_split(char const *s, char c);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 나눌 문자열<br/>
        #2. 구분할 문자</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>split으로부터 나온 새로운 문자열들의 배열<br/>
        할당에 실패할 경우 NULL 반환.</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>`malloc`, `free`</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>`s`를 구분자 `c`로 나눈 문자열들의 집합을 할당하고 반환<br/>
        배열은 반드시 NULL포인터로 끝나야함</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_itoa</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>char *ft_itoa(int n);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 변환될 정수</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>정수를 표현하는 문자열<br/>
        할당에 실패할 경우 NULL반환.</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>malloc</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>인수로 받은 정수를 표현하는 문자열을 할당하고 반환<br/>
        음수처리는 필수</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_strmapi</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>char *ft_strmapi(char const *s, char (*f)(unsigned int, char));</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 반복할 문자열<br/>
        #2. 각 문자에 적용할 함수</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>`f` 함수를 연속적으로 적용시킨 문자열<br/>
        할당에 실패할 경우 NULL반환.</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>malloc</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>문자열`s`의 각 문자에 함수`f`를 적용시켜 만든 새로운 문자열 만들기<br/>
        </td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_putchar_fd</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_putchar_fd(char c, int fd);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 출력할 문자<br/>
        #2. 쓰여질 파일디스크럽터</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>write</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>문자 `c`를 주어진 파일디스크럽터로 출력</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_putstr_fd</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_putstr_fd(char *s, int fd);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 출력할 문자열<br/>
        #2. 쓰여질 파일디스크럽터</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>write</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>문자열`s`를 주어진 파일디스크럽터로 출력</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_putendl_fd</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_putendl_fd(char *s, int fd);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 출력할 문자열<br/>
        #2. 쓰여질 파일디스크럽터</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>write</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>문자열`s`를 주어진 파일디스크럽터로 출력하고 newline으로 끝내기</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_putnbr_fd</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_putnbr_fd(int n, int fd);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 출력할 정수<br/>
        #2. 쓰여질 파일디스크럽터</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>write</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>정수`n`을 주어진 파일디스크럽터로 출력</td>
  </tr>
</table>

## Chapter 4 - Bonus Part

당신이 필수파트를 성공적으로 끝마쳤다면, 더 멀리 나아갈 수 있습니다. 보너스 포인트를 위해 이 마지막 섹션을 볼 수 있습니다.

메모리와 문자열을 조작하는 함수는 매우 유용하지만, 당신은 리스트를 조작하는 함수가 더 유용하다는 것을 알아낼 것입니다.

리스트의 요소들을 표현하기 위해 다음 구조를 사용해야 할것입니다. 이 구조는 반드시 당신의 `libft.h`에 추가해야합니다.

`libft.a`라이브러리에 `make bonus`는 보너스 함수를 추가할 것입니다.

이 파트의 헤더와 \*.c 파일에 `_bonus`를 추가할 필요가 없습니다. 당신의 보너스 함수를 포함하는 파일의 뒤에만 `_bonus`를 붙히세요.

<pre>
typedef struct    s_list
{
  void            *content;
  struct s_list   *next;
}                 t_list;
</pre>

`t_list` 구조체의 필드에 대한 설명입니다.
- content : 요소에 포함되는 데이터. void 포인터는 어떤 종류의 자료형이든 저장할 수 있습니다.
- next    : 다음 요소의 주소.  마지막 요소인 경우에는 NULL.

아래의 함수들은 리스트를 쉽게 사용할 수 있게 해줄 것입니다.

<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstnew</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>t_list *ftlstnew(void *content);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 새로운 요소를 만들 content</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td> 새로운 요소</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>malloc</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>새로운 요소를 할당하고 반환. 변수 'content'는 매개변수 'content'의 값에 따라 초기화된다. 변수 'next'는 NULL로 초기화된다.</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstadd_front</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_lstadd_front(t_list **lst, t_list *new);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 첫번째 연결리스트의 <br/>
        #2. 리스트에 추가될 요소의 포인터 주소</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>리스트의 처음에 'new' 요소를 추가.</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstsize</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>int ft_lstsize(t_list *lst);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 리스트의 첫 부분</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>리스트의 길이</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>리스트 안 요소의 개수.</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstlast</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>t_list *ft_lstlast(t_list *lst);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 리스트의 첫 부분</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>리스트의 마지막 요소</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>리스트의 마지막 요소를 반환/</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstadd_back</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_lstadd_back(t_list **lst, t_list *new);</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 첫번째 연결리스트의 포인터 주소<br/>
        #2. 리스트에 추가될 요소의 포인터 주소</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>리스트의 마지막 부분에 'new'요소 추가</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstdelone</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_lstdelone(t_list *lst, void (*del)(void *));</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. free 할 요소<br/>
        #2. content를 삭제하는데 사용되는 함수의 주소</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>free</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>매개변수의 요소를 가져오고, 매개변수로 주어진 'del'함수를 이용하여 요소의 content의 메모리를 해제, 그리고 요소를 free. 'next'의 메모리는 free하지 말아야한다.</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstclear</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_lstclear(t_list **lst, void (*del)(void *));</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 요소의 포인터 주소<br/>
        #2. 요소의 content를 삭제하는데 쓰이는 함수의 주소</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>free</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>함수 'del'을 이용하여 주어진 요소와 후속되는 모든 요소를 삭제하고 해제. 모든 리스트의 포인터는 NULL로 세팅.</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstiter</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>void ft_lstiter(t_list *lst, void (*f)(void *));</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 요소의 포인터 주소<br/>
        #2. 리스트에 반복적으로 사용될 함수의 주소</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>없음</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>리스트 'lst'를 반복하고 함수 'f'를 각 요소의 content에 적용.</td>
  </tr>
</table>
<table>
  <tr>
    <td>함수 이름</td>
    <td>ft_lstmap</td>
  </tr>
  <tr>
    <td>프로토타입</td>
    <td>t_list ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));</td>
  </tr>
  <tr>
    <td>만들어질 파일</td>
    <td>-</td>
  </tr>
  <tr>
    <td>파라미터</td>
    <td>#1. 요소의 포인터 주소<br/>
        #2. 리스트에 반복적으로 사용되는 함수의 주소<br/>
        #3. 필요한 경우 요소의 content를 삭제하기 위해 사용되는 함수의 주소</td>
  </tr>
  <tr>
    <td>반환 값</td>
    <td>새로운 리스트. 할당이 실패할 경우 NULL</td>
  </tr>
  <tr>
    <td>외부 함수</td>
    <td>malloc, free</td>
  </tr>
  <tr>
    <td>설명</td>
    <td>리스트 'lst'를 반복하여 각 요소의 content에 함수 'f'를 적용. 함수 'f'를 연속적으로 적용시켜 새로운 리스트를 생성. 필요한 경우 'del'함수는 요소의 content를 삭제하는데 사용됨.</td>
  </tr>
</table>


적합하다고 생각한다면, 자신의 libft에 어떠한 함수들도 자유롭게 추가시킬 수 있습니다.
