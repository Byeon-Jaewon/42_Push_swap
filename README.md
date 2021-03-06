# Push_swap
'Swap_push'는 자연스럽지 않으니까요...

*이 프로젝트는 당신에게 제한된 구조들과 최대한 적은 행동을 사용하여 스택의 데이터를 정렬하게 할 것입니다. 완수하기위해 당신은 다양한 알고리즘을 조작해야하고 최적화된 데이터정렬을 하기 위해 가장 적절한 하나를 선택해야 합니다.*


## Chapter1 - 서론

- C
<pre>
#include <stdio.h>
int main(void)
{
  printf("hello, world\n");
  return 0;
} </pre>


- ASM
<pre>cseg segment
assume cs:cseg, ds:cseg
org 100h
main proc
jmp debut
mess db 'Hello world!$'
debut:
mov dx, offset mess
mov ah, 9
int 21h
ret
main endp
cseg ends
end main</pre>
- LOLCODE
<pre>HAI
CAN HAS STDIO?
VISIBLE "HELLO WORLD!"
KTHXBYE</pre>
- PHP
```{.php}
<?php
echo "Hello world!";
?>
```


- BrainFuck
<pre>++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.
<<+++++++++++++++.>.+++.------.--------.>+.>.</pre>
- C#
<pre>using System;

public class HelloWorld {
  public static void Main () {
    Console.WriteLine("Hello world!");
  }
}</pre>
- HTML5
```
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Hello world !</title>
  </head>
  <body>
    <p>Hello World !</p>
  </body>
</html>
```
- YASL
<pre>"Hello world!"
print</pre>
- Ocaml
<pre>let main () =
  print_endline "Hello world !"
  
let _ = main ()</pre>


## Chapter 2 - 소개
`Push_swap`프로젝트는 아주 간단하고 상당히 효과적인 알고리즘 프로젝트입니다 : 데이터는 반드시 정렬될 필요가 있습니다. 당신은 두 개의 스택들과 두 스택 모두를 조작할 명령어의 집합, Int 값들의 집합을 처리해야 합니다.   
  
  
   목표? C로 `push_swap`프로그램을 작성하세요. `Push_swap`은 정수형 인자를 받아 `Push_swap`명령어를 이용해 정렬하고 계산해서 표준출력으로 표시하는 프로그램입니다.


  쉬울까요?


  글쎄요...


## Chpater 3 - 목표
정렬 알고리즘을 작성하는 것은 **복잡도** 개념을 처음 마주하기 때문에 개발자 인생의 가장 중요한 단계입니다.   


  정렬알고리즘과 그들의 복잡도는 취직면접에서 논의되는 고전적인 질문입니다. 언젠가 한번은 마주해야 할 것이기 때문에 그 개념을 찾는 좋은 시간이 될겁니다.   
  
  
  이 프로젝트의 학습 목표는 엄격함과 C의 사용 및 기본 알고리즘의 사용입니다. 특히 이런 기본 알고리즘의 복잡도를 살펴보는 것.
  
  값을 정렬하는건 간단합니다. 하지만 정수구성마다 가장 효율적인 정렬알고리즘이 다를 수 있기 때문에 가능한 빨리 정렬하는 것은 그렇게 간단하진 않습니다.
  
  
## Chapter 4 - 일반적인 지침

- 이 프로젝트는 사람에 의해서만 채점됩니다. 그러므로 당신은 아래 나열된 몇몇 요구사항을 준수해야하지만 원하는대로 파일을 구성하고 이름을 지정할 수 있습니다.
- 실행파일의 이름은 `push_swap`이여야만 합니다.
- 반드시 `Makefile`을 제출해야 합니다. `Makefile`은 프로젝트를 컴파일하고 일반 규칙들을 포함해야합니다. 필요한 경우 프로그램을 다시 컴파일 할 수 습니다.
- 머리가 좀 돌아간다면, 이 프로젝트에 당신의 라이브러리를 이용할 것이고, 저장소의 root에 libft의 폴더와 Makefile을 제출해야 합니다. Makefile은 라이브러리를 컴파일하고 프로젝트를 컴파일해야 할 것입니다.
- 전역변수는 금지입니다~
- `Norm`을 준수한 **C**로 작성해야 합니다.
- 오류를 민감하게 처리해야 합니다. 예기치 않은 방식으로 프로그램을 종료할 방법은 없습니다. (Segmentation fault, bus error, double free, 등)
- 메모리 누수가 발생하면 안됩니다~
- 필수 파트 안에서는 아래의 함수를 사용할 수 있습니다~
<pre>write, read, malloc, free, exit</pre>
- 슬랙이나 포럼에 질문하세용~








## Chapter 5 - 필수 파트~

### 5.1 Game rules~
- 게임은 `a`와 `b`라는 두개의 **스택**을 구성합니다.
- 시작하기전에 :
  - `a`는 중복없이 무작위의 양수나 음수를 포함합니다.
  - `b`는 비어있습니다.
- 목표는 `a`스택 안에 오름차순으로 정렬하는 것입니다.
- 이를 수행하기 위해 따라오는 연산들을 처리해야 합니다.

  **sa** : `swap a` - 스택 a의 맨 위에 있는 두 요소를 스왑한다. (요소가 하나뿐이거나 없다면 아무것도 하지 않는다.)  
  **sb** : `swap b` - 스택 b의 맨 위에 있는 두 요소를 스왑한다. (요소가 하나뿐이거나 없다면 아무것도 하지 않는다.)   
  **ss** : `sa`와 `sb`를 동시에 수행한다.   
  **pa** : `push a` - 스택 b의 맨 위에 있는 요소를 스택 a의 맨 위에 놓는다. (b가 비어있다면 아무것도 하지 않는다.)   
  **pb** : `push b` - 스택 a의 맨 위에 있는 요소를 스택 b의 맨 위에 놓는다. (a가 비어있다면 아무것도 하지 않는다.)   
  **ra** : `rotate a` - 스택 a의 모든 요소를 1씩 올린다. (첫 요소가 마지막이 되도록)   
  **rb** : `rotate b` - 스택 b의 모든 요소를 1씩 올린다. (첫 요소가 마지막이 되도록)   
  **rr** : `ra`와 `rb`를 동시에 수행한다.   
  **rra** : `reverse rotate a` - 스택 a의 모든 요소를 1씩 내린다. (마지막 요소가 첫 요소가 되도록)   
  **rrb** : `reverse rotate b` - 스택 b의 모든 요소를 1씩 내린다. (마지막 요소가 첫 요소가 되도록)   
  **rrr** : `rra`와 `rrb`를 동시에 수행한다.   
  
### 5.2 예시
이 명령어들의 효과를 설명하기 위해 정수형 리스트를 정렬해봅시다.   
이 예에서 우리는 두 스택이 모두 오른쪽으로부터 확장되는 것을 고려합니다.   
<pre>
---------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
---------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
---------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
---------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
---------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
---------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
---------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
---------------------------------------------------------</pre>
      이 예시에선 `a`에 정렬하기 위해 12개의 명령어를 사용했습니다. 더 잘할 수 있나요?


### 5.3 "push_swap" 프로그램

- 당신은 정수형 리스트로 포맷된 스택을 인수로 받는 `push_swap` 프로그램을 작성해야합니다. 첫 인수는 스택의 맨 위에 있어야 합니다.(순서에 주의하세용)
- 프로그램은 스택 a의 정렬을 위해 가능한 가장 적은 명령어의 리스트를 표준출력으로 출력해야합니다.
- 명령어는 반드시 '\n'으로 분리되어야 하며 다른 것은 없어야 합니다.
- 목표는 가능한 최소의 연산을 사용하여 스택을 정렬하는 것입니다. 디펜스 동안 우리는 허용되는 최대의 연산과 당신의 프로그램이 발견한 명령어의 수를 비교할 것입니다. 만약 당신의 프로그램이 리스트를 너무 크게 표시하거나 제대로 정렬하지 않는다면, 당신은 점수를 받을 수가 없습니다!!!!!
- 에러상황에서, 당신은 표준에러로 `Error\n'를 표시해야 합니다.
- 오류에 포함되는 예시 : 일부 인수가 정수가 아닐 경우, 일부 인수가 정수형보다 클 경우, 또는 중복될 경우

<pre>$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
</pre>


  디펜스하는 동안, 우리는 당신의 프로그램을 체크할 프로그램을 제공할 것입니다.
<pre>$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$></pre>
    
    
 `checker_OS`프로그램이 KO를 표시할 경우, 당신의 push_swap에서 나온 명령어리스트가 리스트를 정렬하지 못했다는것을 의미합니다.   
 `checker_OS`프로그램은 이트라넷의 프로젝트 리소스에 가면 사용할 수 있습니다. 이 문서의 보너스 파트에서 어떻게 쓰는지 설명합니다.
     
## Chapter 6 - 보너스 파트


필수파트가 완벽할때만 보너스 파트를 검토하겠습니다.   
필수파트를 처음부터 끝까지 끝냈어야 하고, 잘못되거나 뒤틀린 사용에 있어서도 에러관리가 완벽해야합니다.   
만약 그렇지 않다면? 보너스는 무시됩니다 ㅋ   

~~당신의 코드를 검사하는 프로그램을 당신이 만든다면~? 개재밌겠다~!~~

### 6.1 - "Checker"프로그램
- checker라는 프로그램을 작성할 때, 정수형 리스트로 포맷된 스택을 인수로 받습니다. 첫 인수는 스택의 맨 위에 있어야 합니다.(순서에 주의하세용) 인수가 없는 경우 체커는 중지되고 아무것도 표시하지 않습니다.
- checker는 각각의 명령어 뒤에 '\n'이 붙은 표준입력에 대해 명령어를 기다리고 읽을 것입니다. 모든 명령어를 읽게되면, checker는 인수로 받은 스택에서 실행할 것입니다.
- 만약 명령어를 실행한 후에 스택 a가 정렬되고 b가 비어있다면, checker는 `OK\n`를 표준출력으로 표시합니다. 다른 모든 경우는 `KO\n`를 표시합니다.
- 오류가 발생한다면, 표준에러에 `Error\n`를 표시합니다. 
- 에러는 다음의 예시를 포함합니다 : 일부 인수가 정수가 아니거나, 정수보다 크거나, 중복되거나, 명령이 없거나, 잘못된 인수거나
> checker 프로그램 덕분에 `push_swap`프로그램으로 생성할 명령어 목록이 실제로 스택을 제대로 정렬하고 있는지 확인할 수 있습니다~
<pre>$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$></pre>

## Chapter 7 - 제출과 동료평가 
평소와 같이 git 레포지토리에 결과물을 제출하세요~ 레포지토리에서 작동하는 것만 채점될거에요~    
행운을 빕니다 모두~
