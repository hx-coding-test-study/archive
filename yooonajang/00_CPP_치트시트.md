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
- C++는 변수를 반드시 초기화하자. `int cnt = 0;` (초기화 안 하면 쓰레기값)

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
```

**2차원 vector (격자 문제 필수):**
```cpp
vector<vector<int>> grid(n, vector<int>(m, 0));  // n행 m열, 0으로 채움
grid[i][j] = 5;
int rows = grid.size(), cols = grid[0].size();
```

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
char c = '7';
c - '0';               // 문자 '7' → 숫자 7   (핵심 트릭!)
(char)('0' + 5);       // 숫자 5 → 문자 '5'
c >= 'a' && c <= 'z';  // 소문자인지
isdigit(c);            // 숫자 문자인지 (#include <cctype>)
isalpha(c);            // 알파벳인지
tolower(c); toupper(c);// 대소문자 변환
```

### 2-3. pair / tuple (두 값 묶기)

```cpp
#include <utility>
pair<int,int> p = {3, 5};
p.first;  p.second;               // 3, 5
vector<pair<int,int>> vp;
vp.push_back({1, 2});
// 정렬하면 first 기준 → 같으면 second 기준 자동 정렬
```

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
// LIFO: 짝 맞추기(괄호), 최근 것 되돌리기

#include <queue>
queue<int> q;
q.push(1); q.front(); q.pop(); q.empty(); q.size();
// FIFO: BFS, 순서대로 처리(프린터/트럭)
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
count(v.begin(), v.end(), 3);       // 3의 개수
find(v.begin(), v.end(), 3);        // 위치 (없으면 v.end())
reverse(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0);  // 합 (파이썬 sum) — 세 번째는 시작값
__gcd(a, b);                        // 최대공약수 (LCM = a/__gcd(a,b)*b)
```

**정렬 커스텀 (람다 = 파이썬 key/lambda):**
```cpp
// 내림차순
sort(v.begin(), v.end(), [](int a, int b){ return a > b; });

// 문자열 길이 순, 같으면 사전순
sort(vs.begin(), vs.end(), [](const string& a, const string& b){
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
});
```

**순열 완전탐색 (모든 순서 다 보기):**
```cpp
sort(v.begin(), v.end());               // 반드시 먼저 정렬!
do {
    // v의 현재 순열로 뭔가 한다
} while (next_permutation(v.begin(), v.end()));
```

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
#include <queue>
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
