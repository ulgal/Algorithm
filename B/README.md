## Tip for B
* NULL 선언하기
```c++
#define NULL 0
```
* 자주 사용하는 변수(ex for문 내 i) register 키워드 사용
```c++
for(int register i = 0; i < 1000000; ++i){
    doSomething();
}
```
* Inline method 대신 define 사용
```c++
#define max(a,b) ((a)>(b) ? (a) : (b))
x = max(x, y)
/**
 * x, y에는 식이 들어가면 중복 call 생기므로
 * y = something();
 * x = max(x, y) 같은 방식 이용
 */
x = (x>y) ? (x) : (y)
```
* Linked List는 정적 할당
* Locality, Lazy, Share 고려
* 개수가 적다면 linear search, 많다면 Hash Table with chaining
* 자료 구조의 배열이 커지면 불합격할 가능성이 높아진다
* 불필요한 연산 및 복제 피하기
* 설계 기반 구현 최적화