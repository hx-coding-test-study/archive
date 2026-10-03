# C++ 코딩테스트 치트시트 (파이썬 → C++ 벼락치기)

> 목표: 프로그래머스 Lv1~2(상), 완전탐색·시뮬레이션·구현·기본 자료구조.
> 이 파일 하나로 문법 + STL + 알고리즘 템플릿을 다 외운다.

---

## 0. 프로그래머스 기본 뼈대

프로그래머스는 `solution` 함수만 채우면 된다. `main`, 입력받기(`cin`)는 필요 없다.

```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;   // 이거 안 쓰면 std::vector, std::sort 처럼 다 붙여야 함

int solution(vector<int> arr) {   // 반환 타입/파라미터는 문제가 정해줌 (수정 금지)
    int answer = 0;
    // ... 여기 채우기
    return answer;
}
```

반환 타입 자주 나오는 것: `int`, `long long`, `string`, `vector<int>`, `vector<string>`.

**헤더 요약표 (뭘 쓰든 이 중 하나):**

| 헤더 | 이걸 쓸 때 |
|---|---|
| `<vector>` | `vector` |
| `<string>` | `string`, `stoi`, `to_string` |
| `<algorithm>` | `sort`, `find`, `count`, `max_element`, `min_element`, `reverse`, `next_permutation`, `max`, `min` |
| `<utility>` | `pair` (보통 `<vector>`/`<queue>` 등에 딸려와서 안 써도 되는 경우 많음) |
| `<map>` | `map`, `unordered_map` |
| `<set>` | `set`, `unordered_set` |
| `<stack>` | `stack` |
| `<queue>` | `queue`, `priority_queue` |
| `<cctype>` | `isdigit`, `isalpha`, `tolower`, `toupper` |
| `<numeric>` | `accumulate` |
| `<sstream>` | `stringstream` (문자열 split용) |
| `<iostream>` | `cout` (디버깅 출력용, 제출 코드엔 없어도 됨) |

헷갈리면 일단 `#include <bits/stdc++.h>` 하나로 전부 해결(모든 표준 헤더를 통째로 불러옴)하는 방법도 있다 — 프로그래머스는 대부분 허용됨. 급하면 이거 하나만 쓰고 시작해도 됨.

디버깅용 출력(제출 코드엔 지워도 됨):
```cpp
#include <iostream>
cout << x << " " << y << "\n";   // 파이썬 print(x, y)
```

---

## 1. 파이썬 → C++ 문법 대응표

| 파이썬 | C++ |
|--------|-----|
| `x = 5` | `int x = 5;` (타입 명시 + 세미콜론!) |
| `s = "hi"` | `string s = "hi";` |
| `x = 3.14` | `double x = 3.14;` |
| `flag = True` | `bool flag = true;` |
| `c = 'a'` (한 글자) | `char c = 'a';` (**작은따옴표 = 문자**, 큰따옴표 = 문자열) |
| `#주석` | `// 주석` 또는 `/* ... */` |
| `and or not` | `&& \|\| !` |
| `if a: ... elif b: ... else:` | `if(a){...} else if(b){...} else {...}` |
| `for i in range(n):` | `for(int i=0;i<n;i++){ ... }` |
| `for x in arr:` | `for(int x : arr){ ... }` (범위 기반) |
| `while cond:` | `while(cond){ ... }` |
| `a // b` (정수 나눗셈) | `a / b` (**둘 다 int면 자동으로 몫**) |
| `a % b` | `a % b` |
| `a ** b` (거듭제곱) | `pow(a,b)` (실수) 또는 반복문. int 거듭제곱은 직접 곱하기 |
| `len(x)` | `x.size()` |
| `abs(x)` | `abs(x)` |
| `min(a,b) / max(a,b)` | `min(a,b) / max(a,b)` (`#include <algorithm>`) |

**타입 함정 (파이썬 습관 때문에 잘 틀림):**
- `int`는 약 ±21억까지. 합이 커질 것 같으면 `long long` 사용. (`int`끼리 곱하면 오버플로 조심)
- `5 / 2` 는 `2` (정수 나눗셈). 실수 원하면 `5.0 / 2`.
- 변수끼리 나눌 땐 **하나만** 바로 앞에 `(double)` 붙이기: `(double)a / b` ✅ / `1.0 * a / b` ✅ / `(double)(a / b)` ❌ (괄호 안에서 int 나눗셈이 먼저 끝나서 소용없음)
- `double` **0 / 0은 안 죽고 `nan`**이 나옴. `nan`은 어떤 비교도 `false`라서 `sort`가 깨짐 → 나누기 전에 분모 0인지 꼭 체크 (실패율 문제).
- `float` 말고 `double` 쓰기 (float는 소수점 7자리 정도라 정밀도 부족).
- C++는 변수를 반드시 초기화하자. `int cnt = 0;` (초기화 안 하면 쓰레기값)

**`%`로 패턴 순환시키기 (짧은 패턴을 계속 반복해야 할 때 — 모의고사류):**
```cpp
vector<int> pattern = {2,1,2,3,2,4,2,5};   // 길이 8짜리 패턴
for (int i = 0; i < n; i++) {
    int cur = pattern[i % pattern.size()];   // i가 패턴 길이를 넘어가면 처음부터 반복
}
```

---

## 2. 필수 STL (★ 이게 핵심 ★)

### 2-1. vector = 파이썬 list

```cpp
#include <vector>
vector<int> v;                 // 빈 리스트
vector<int> v = {1, 2, 3};     // 초기값
vector<int> v(5);              // 0으로 채운 크기 5
vector<int> v(5, 7);           // 7로 채운 크기 5

v.push_back(10);   // append(10)
v.pop_back();      // 맨 뒤 삭제
v.size();          // len(v)
v.empty();         // len(v)==0 인지 (true/false)
v[0];              // 인덱싱 (음수 인덱스 없음! v[-1] 안 됨)
v.back();          // 마지막 원소 (v[-1] 대신)
v.front();         // 첫 원소
v.clear();         // 전부 비우기
sort(v.begin(), v.end());          // 오름차순 정렬
sort(v.rbegin(), v.rend());        // 내림차순 정렬
reverse(v.begin(), v.end());       // 뒤집기

for (int x : v) { ... }            // 값 순회
for (int i = 0; i < v.size(); i++) // 인덱스 순회

v.erase(v.begin() + 1);            // 인덱스 1번 원소 삭제 (뒤 원소 전부 한칸씩 당김, O(n))
v.erase(v.begin()+1, v.begin()+3); // 인덱스 1,2번 삭제 (3번은 미포함, 파이썬 슬라이스 느낌)

#include <algorithm>
count(v.begin(), v.end(), 2);      // 2가 몇 번 나오는지 개수 (파이썬 list.count(x))
find(v.begin(), v.end(), 2) != v.end();  // 2가 있는지 (파이썬 `2 in v`, 없으면 v.end() 반환)
```

**`begin()` / `end()`가 뭔지 (외우지 말고 이해하기):**

인덱스(정수)가 아니라, 원소를 가리키는 "화살표"(iterator)다. `begin()`은 0번째를 가리키고, `end()`는 마지막 원소 "다음"의 아무것도 없는 자리 — 그냥 "여기서 끝났다"는 표시일 뿐이다.

```cpp
vector<int> v = {10, 20, 30};
find(v.begin(), v.end(), 20);   // 찾으면 그 위치(화살표) 반환
find(v.begin(), v.end(), 99);   // 못 찾으면 v.end() 그대로 반환 (끝까지 갔는데 없더라)

find(v.begin(), v.end(), 20) != v.end();   // bool: 있는지 없는지 (비교해야 bool이 나옴)
find(v.begin(), v.end(), 20) - v.begin();  // int: 몇 번째에 있는지 (화살표끼리 빼면 인덱스로 변환됨)
```

- `find()` 자체는 bool도 인덱스도 아니고 **위치(iterator)**를 반환한다. bool이 필요하면 `!= v.end()`로 비교, 인덱스가 필요하면 `- v.begin()`으로 변환해야 한다.
- `v.erase(v.begin() + i)`의 `v.begin() + i`도 같은 개념: "화살표를 i칸 옮긴 위치" = 인덱스 i번째.

**파이썬 인덱싱/슬라이싱 흉내내기 (C++엔 그런 문법 자체가 없음):**

| 파이썬 | C++ |
|---|---|
| `arr[-1]` | ❌ 안 됨(조용히 틀린값 읽음) → `v.back()` |
| `arr[-2]` | `v[v.size()-2]` |
| `arr[a:b]` | `vector<int> sub(v.begin()+a, v.begin()+b);` |
| `arr[:b]` | `vector<int> sub(v.begin(), v.begin()+b);` |
| `arr[a:]` | `vector<int> sub(v.begin()+a, v.end());` |
| `arr[::-1]` | `reverse(v.begin(), v.end());` (제자리 뒤집기) |

**`map`/`set`의 `.count(x)`는 개수가 아니라 "있는지(0/1)"만 알려줌** (중복이 없는 자료구조라서):
```cpp
set<int> s = {1,2,3};
s.count(2);   // 1 (있음), s.count(5) // 0 (없음)
```

**2차원 vector (격자 문제 필수):**
```cpp
vector<vector<int>> grid(n, vector<int>(m, 0));  // n행 m열, 0으로 채움
grid[i][j] = 5;
int rows = grid.size(), cols = grid[0].size();
```

**왜 저렇게 생겼는지 (외우지 말고 이해하기):**

기본 패턴은 `vector<T>(개수, 채울값)` = "개수만큼 채울값을 복사해서 채워라" 하나뿐이다. 이걸 안쪽→바깥쪽으로 두 번 적용한 것뿐이다.

1. 안쪽 `vector<int>(m, 0)` → "크기 m, 전부 0" = **행 하나** 만들기: `{0,0,...,0}` (m개)
2. 바깥쪽 `vector<vector<int>>(n, 위에서 만든 행)` → "크기 n, 전부 (그 행)으로 채움" = **그 행을 n개 복사**

결과: n행 × m열, 전부 0. `vector<vector<bool>> visited(n, vector<bool>(m, false));` 도 똑같은 원리 (bool/false만 다름).

### 2-1a. 참조(`&`) — for문/함수에서 원본을 진짜로 수정하기

**`for (vector<int> v : board)` (& 없이)는 `board`의 각 행을 "복사"해서 도는 것.** `v`를 아무리 고쳐도 `board` 원본은 그대로다. `v[i]=0` 해도 원본은 안 바뀐다 — **크레인 인형뽑기에서 자주 하는 실수.**

```cpp
for (vector<int>& v : board) {   // & 붙여야 진짜 board를 수정 가능
    v[0] = 0;   // 이제 board 원본이 바뀜
}
```

**왜 이렇게 되는지:** `&`는 포인터가 아니라 "원본의 또 다른 이름(별명)"이다. `int& d = c;` 하면 `d`랑 `c`는 완전히 같은 상자를 가리키는 두 이름일 뿐이라, `d`를 고치면 `c`도 (애초에 같은 것이므로) 같이 바뀐다. `&` 없이 대입하면 새 상자를 만들어 값만 복사하니, 서로 남남이 된다.

```cpp
int a = 5;
int b = a;    // 복사: b를 바꿔도 a는 그대로
int& c = a;   // 참조: c는 a의 별명, c를 바꾸면 a도 바뀜
```

**파이썬과 다른 점 (중요):** 파이썬은 기본이 참조라서(변수가 전부 "이름표"), `for row in board: row[0]=0` 하면 **자동으로 원본이 바뀐다.** C++는 기본이 복사라서, 원본을 바꾸려면 `&`를 **명시적으로** 써야 한다.

> 파이썬 에러 "반복 중 리스트/딕셔너리 크기 변경" (`dictionary changed size during iteration` 등)은 이거랑 다른 얘기다 — 그건 반복 도중 **원소 개수(구조)**를 바꿀 때 나는 에러고, `v[i]=0`처럼 **이미 있는 값만 바꾸는 것**은 파이썬/C++ 둘 다 안전하다.

### 2-2. string = 파이썬 str (단, 수정 가능!)

```cpp
#include <string>
string s = "hello";
s.size();              // len
s[0];                  // 'h' (char)
s += "!";              // 이어붙이기 (s = s + "!" 도 됨)
s.push_back('x');      // 문자 하나 추가
s.pop_back();          // 마지막 문자 삭제
s.substr(1, 3);        // 인덱스1부터 3글자 = 파이썬 s[1:4]
s.substr(2);           // 인덱스2부터 끝까지 = s[2:]
s.find("ll");          // 위치 반환, 없으면 string::npos
reverse(s.begin(), s.end());   // 문자열 뒤집기
sort(s.begin(), s.end());      // 문자 정렬

stoi("123");           // 문자열 → int  (파이썬 int("123"))
stoll("100000000000"); // 문자열 → long long
to_string(123);        // 숫자 → 문자열 (파이썬 str(123))
```

**문자(char) 다루기 — 아주 자주 씀:**
```cpp
#include <cctype>   // isdigit, isalpha, tolower, toupper 전부 이 헤더
char c = '7';
c - '0';               // 문자 '7' → 숫자 7   (핵심 트릭! 이건 include 필요 없음, 그냥 뺄셈)
(char)('0' + 5);       // 숫자 5 → 문자 '5'
c >= 'a' && c <= 'z';  // 소문자인지 (이것도 include 필요 없음)
isdigit(c);            // 숫자 문자인지
isalpha(c);            // 알파벳인지
tolower(c); toupper(c);// 대소문자 변환
```

### 2-3. pair (정확히 2개를 묶기)

`vector`와 달리 **딱 2개만** 담는 상자. 좌표(행,열)처럼 "항상 2개로 고정된 값"에 쓴다.

```cpp
#include <utility>
pair<int,int> p = {3, 5};
p.first;  p.second;               // 3, 5 (인덱스 아니라 고정된 이름)

vector<pair<int,int>> vp = {{1,2}, {0,3}};   // pair 여러 개 담은 목록 (좌표 리스트)
vp[0].first;    // 1
vp[0].second;   // 2
for (pair<int,int> p : vp) { ... }           // 순회

auto [x, y] = p;   // 구조분해(C++17): first/second를 한번에 변수로 꺼냄 (BFS에서 자주 씀)

// 정렬하면 first 기준 → 같으면 second 기준 자동 정렬
```

**`vector` vs `pair` 구분:**

| | `vector<T>` | `pair<T1,T2>` |
|---|---|---|
| 담는 개수 | 여러 개 (0개~N개) | 딱 2개 고정 |
| 접근 방법 | `v[0]`, `v[1]`... (인덱스) | `.first`, `.second` (고정된 이름) |
| 파이썬 비유 | list | 길이 2인 tuple |

- `vector<int, int>` ← ❌ **문법 자체가 잘못됨.** `vector<>`의 두 번째 자리는 값 타입이 아니라 내부 옵션(allocator) 자리라 컴파일 에러 남. "2개 고정"을 표현하려면 `pair<int,int>`를 쓸 것.
- 좌표 여러 개를 담고 싶으면 `vector<pair<int,int>>` 또는 `vector<vector<int>>` 둘 다 가능 (편한 거 쓰면 됨).

### 2-4. map / unordered_map = 파이썬 dict

```cpp
#include <map>              // map: 키 정렬됨(느림) / unordered_map: 정렬X(빠름)
map<string,int> cnt;
cnt["apple"]++;            // 없으면 0에서 시작 → 1 (defaultdict 처럼 동작)
cnt["apple"] = 3;
cnt.count("apple");        // 있으면 1, 없으면 0 (존재 확인)
cnt.size();

for (auto& [key, val] : cnt) {     // 딕셔너리 순회 (C++17)
    // key, val 사용
}
```
> 개수 세기(빈도수) 문제엔 `map<T,int>` 가 국룰. (해시 유형)

### 2-5. set = 파이썬 set (중복 제거 + 존재 확인)

```cpp
#include <set>
set<int> s;               // 자동 정렬 + 중복 없음
s.insert(5);
s.count(5);               // 있으면 1 (in 연산자 대신)
s.erase(5);
s.size();
for (int x : s) { ... }   // 오름차순으로 순회됨
// unordered_set 은 정렬 안 되지만 더 빠름
```

### 2-6. stack / queue (자료구조 유형 필수)

```cpp
#include <stack>
stack<int> st;
st.push(1); st.top(); st.pop(); st.empty(); st.size();
// LIFO(나중에 넣은 게 먼저 나옴): 짝 맞추기(괄호), 최근 것 되돌리기, "바구니"류 문제

#include <queue>
queue<int> q;
q.push(1); q.front(); q.pop(); q.empty(); q.size();
// FIFO(먼저 넣은 게 먼저 나옴): BFS, 순서대로 처리(프린터/트럭)
```

**주의**: `queue`는 `front()`로 맨 앞을 보고, `stack`은 `top()`으로 맨 위를 본다 — 이름이 달라서 헷갈리기 쉽다. 둘 다 `pop()`은 반환값이 없다(값을 보려면 먼저 `front()`/`top()`으로 보고 나서 `pop()`).

**stack 실전 패턴 — "방금 넣은 것과 그 아래 것 비교" (크레인 인형뽑기류):**
```cpp
#include <stack>
stack<int> basket;
basket.push(3);

if (basket.size() >= 2) {
    int x = basket.top();   // 방금 넣은 것
    basket.pop();
    int y = basket.top();   // 그 바로 아래 것

    if (x == y) {
        basket.pop();       // 같으면 둘 다 제거
    } else {
        basket.push(x);     // 다르면 되돌리기 (뺐던 걸 다시 넣음)
    }
}
```

### 2-7. priority_queue (우선순위 큐 = 힙)

```cpp
#include <queue>
priority_queue<int> pq;                                  // 최대 힙 (top이 제일 큼)
priority_queue<int, vector<int>, greater<int>> minpq;    // 최소 힙 (top이 제일 작음)
pq.push(3); pq.top(); pq.pop(); pq.empty();
```
> 파이썬 heapq는 최소 힙이었지만, C++ `priority_queue` 기본은 **최대 힙**. 주의!

---

## 3. `<algorithm>` 자주 쓰는 함수

```cpp
#include <algorithm>
#include <numeric>   // accumulate

sort(v.begin(), v.end());
max_element(v.begin(), v.end());    // 최댓값 위치 → 값은 *max_element(...)
min_element(v.begin(), v.end());
// count, find는 2-1(vector) 참고 — begin()/end() iterator 개념도 거기 정리해둠
reverse(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0);  // 합 (파이썬 sum) — 세 번째는 시작값
__gcd(a, b);                        // 최대공약수 (LCM = a/__gcd(a,b)*b)
```

**`max(a,b)` vs `max_element(v.begin(),v.end())` 헷갈리지 말 것:**

| | 대상 | 반환값 |
|---|---|---|
| `max(a, b)` | 값 **2개** | 값 그대로 (`*` 필요 없음) |
| `max_element(begin,end)` | **범위**(vector 전체) | 위치(iterator) → `*` 붙여야 값, `- begin()` 하면 인덱스 |

**주의: `max_element`(`find`도 마찬가지)는 조건에 맞는 것 중 "제일 처음 것" 딱 하나의 위치만 준다.** 최댓값이 여러 개(공동 1등 등)면, `*max_element(...)`로 **값**만 구하고, 그 값과 같은 걸 **직접 for문으로 전부** 찾아야 한다 (모의고사 유형).

```cpp
#include <algorithm>   // max_element도 sort/find랑 같은 헤더
int maxScore = *max_element(score.begin(), score.end());
vector<int> winners;
for (int i = 0; i < score.size(); i++)
    if (score[i] == maxScore) winners.push_back(i);   // 공동 1등 전부 수집
```

**정렬 커스텀 — 방법 1: 음수 트릭 (compare 없이, 제일 쉬움)**

`pair`는 그냥 `sort`해도 **first 오름차순 → 같으면 second 오름차순**으로 정렬된다. 내림차순 원하는 값에 `-`만 붙여서 넣으면 됨.
```cpp
#include <algorithm>
vector<pair<double,int>> v;
v.push_back({-실패율, 번호});   // 실패율 내림차순, 번호 오름차순
sort(v.begin(), v.end());
for (auto p : v) answer.push_back(p.second);
```

**정렬 커스텀 — 방법 2: compare 함수 (기준이 여러 개거나 음수로 안 될 때)**

`compare(a, b)`가 `true` = **"a가 b보다 앞에 온다"**. `sort`는 두 개씩 꺼내서 이 함수에 물어보고 그 답대로 자리를 정한다. 즉 `return` 뒤에 **"a가 앞에 오려면 a가 어때야 하는지"**를 쓴다.
- 큰 게 앞 (내림차순) → `return a > b;`
- 작은 게 앞 (오름차순) → `return a < b;`

```cpp
#include <algorithm>

// ✅ solution 바깥(위)에 써야 함. C++는 함수 안에 함수를 못 만듦 → 안에 쓰면 컴파일 에러
bool compare(pair<double,int> a, pair<double,int> b) {
    if (a.first != b.first) return a.first > b.first;   // 1순위: 다르면 이걸로 결정 (실패율 큰 게 앞)
    return a.second < b.second;                         // 2순위: 같을 때만 여기 옴 (번호 작은 게 앞)
}

vector<int> solution(...) {
    sort(v.begin(), v.end(), compare);   // 함수 이름만, () 없이
}
```

기준이 3개 이상이면 `if (!=) return` 줄을 계속 이어 붙이고, 마지막 기준만 `if` 없이 `return`:
```cpp
bool compare(Person a, Person b) {
    if (a.score != b.score) return a.score > b.score;   // 점수 큰 게 앞
    if (a.age != b.age)     return a.age < b.age;       // 나이 작은 게 앞
    return a.name < b.name;                             // 이름 사전순
}
```
- `return`에서 함수가 끝나니까 `else` 필요 없음.
- `==` 버전(`if (a.first == b.first) return 2순위; return 1순위;`)도 같은 뜻이지만, 기준 3개 이상이면 `!=` 버전이 훨씬 편함.

**compare 주의:**
- **`>=`, `<=` 절대 금지.** 같을 때 `true`가 나오면 정렬이 깨지거나 런타임 에러.
- 같은 값끼리 **원래 입력 순서 유지**해야 하면 `stable_sort(v.begin(), v.end(), compare);`
- 원소가 크면(`string` 등) `const pair<double,int>& a`처럼 `const &`로 받으면 복사 안 해서 빠름 (안 해도 보통 통과).

**방법 3: 람다** — compare 함수를 sort 안에 바로 써넣은 것. 뜻은 방법 2랑 똑같음.
```cpp
sort(vs.begin(), vs.end(), [](const string& a, const string& b){
    if (a.size() != b.size()) return a.size() < b.size();   // 길이 짧은 게 앞
    return a < b;                                           // 같으면 사전순
});
```
파이썬 `sorted(v, key=lambda x: (-x[0], x[1]))`와 같은 결과.

**순열 완전탐색 (모든 순서 다 보기):**
```cpp
#include <algorithm>   // next_permutation도 sort/find랑 같은 헤더
sort(v.begin(), v.end());               // 반드시 먼저 정렬!
do {
    // v의 현재 순열로 뭔가 한다
} while (next_permutation(v.begin(), v.end()));
```
값이 같은 원소가 있으면 `next_permutation`이 중복 순열을 알아서 건너뛴다 (값 비교 기반이라 별도 처리 불필요).

---

## 4. 알고리즘 템플릿 (통째로 외우기)

### 4-1. 완전탐색 — 재귀/백트래킹

```cpp
// 예: 원소를 뽑거나 안 뽑거나(부분집합), 조합 등
void dfs(int idx, /* 상태들 */) {
    if (idx == n) {           // 끝까지 다 정했으면
        // 정답 후보 처리
        return;
    }
    // 선택 1: idx 원소 사용
    dfs(idx + 1, ...);
    // 선택 2: 사용 안 함
    dfs(idx + 1, ...);
}
```

### 4-2. DFS (격자/그래프)

```cpp
int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int dx[4] = {0,0,1,-1};   // 상하좌우 방향벡터 (외워두면 편함)
int dy[4] = {1,-1,0,0};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 범위 밖
        if (visited[nx][ny]) continue;                        // 이미 방문
        if (grid[nx][ny] == 0) continue;                      // 못 가는 칸
        dfs(nx, ny);
    }
}
```

### 4-3. BFS (최단거리는 무조건 BFS)

```cpp
#include <queue>       // queue<pair<int,int>>
#include <vector>      // dist 배열
// pair는 <utility> 소속이지만 보통 <queue>/<vector>가 알아서 딸려옴. 안 되면 #include <utility> 추가.
int bfs(int sx, int sy) {
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));  // -1 = 미방문
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] != -1) continue;      // 이미 방문
            if (grid[nx][ny] == 0) continue;       // 벽
            dist[nx][ny] = dist[x][y] + 1;         // 한 칸 더
            q.push({nx, ny});
        }
    }
    return dist[tx][ty];   // 목표 지점까지의 거리
}
```

### 4-4. 문자열 split (C++엔 내장 split이 없음)

```cpp
#include <sstream>
vector<string> split(string s, char sep) {
    vector<string> res;
    stringstream ss(s);
    string token;
    while (getline(ss, token, sep)) res.push_back(token);
    return res;
}
// split("a,b,c", ',') → {"a","b","c"}
```

---

## 5. 파이썬 습관 때문에 틀리는 것 TOP (시험 직전에 다시 보기)

1. **세미콜론 `;`** 매 줄 끝에. 중괄호 `{}`로 블록.
2. **`v[-1]` 안 됨.** 마지막은 `v.back()`, `v[v.size()-1]`.
3. **정수 나눗셈**: `int/int`는 자동으로 몫. `5/2 == 2`.
4. **오버플로**: 큰 수 곱/합은 `long long`. (`long long ans = (long long)a * b;`)
5. **문자와 숫자**: `'5'`는 문자, `5`는 숫자. 변환은 `c - '0'`.
6. **비교**: 문자열/vector는 `==`로 비교 가능. 다행히 파이썬처럼 됨.
7. **priority_queue 기본은 최대 힙** (파이썬 heapq는 최소였음).
8. **변수 초기화** 잊지 말기: `int cnt = 0;`
9. **인덱스 범위**: 0부터 `size()-1`까지. 벗어나면 런타임 에러/오답.
10. **`size()`는 unsigned**: `for(int i=0; i<(int)v.size(); i++)` 처럼 캐스팅하면 안전 (특히 `v.size()-1`을 뺄 때).

**`core dumped`/런타임 에러 나면 이 순서로 의심 (확률 순):**
1. **인덱스 범위 초과** — `v[i]`에서 i가 음수거나 `size()` 이상인 곳 없는지. 특히 **숫자 하드코딩**(`6` 같은 값 대신 변수 `w`,`n` 써야 하는데 숫자 박아넣은 경우) 제일 흔함. `vector`의 `[]`는 범위 벗어나도 에러 안 내고 조용히 메모리를 깨뜨림(undefined behavior) — 그게 쌓여서 `Segmentation fault (core dumped)`로 터짐.
2. **빈 컨테이너에서 꺼내기** — `stack`/`queue`가 비었는데 `.top()`/`.front()`/`.pop()` 호출. 꼭 `if(!st.empty())` 체크.
3. **2차원 배열 크기/행열 순서 실수** — `grid[i][j]` vs `grid[j][i]`.
4. **재귀 base case 없음** → 무한 재귀로 스택 오버플로우.
5. **0으로 나누기**.

디버깅은 의심되는 `[]` 접근 직전에 `cout << i << " " << v.size() << endl;` 찍어서 범위 확인 (프로그래머스엔 디버거가 없어서 프린트 디버깅이 사실상 유일한 방법).
