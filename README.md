# TeamModernCPP
모던Cpp의 문법을 배우자.

✅ 1강. Modern C++ 문법 입문
목표: C++98 → Modern C++ 문법 전환
핵심: auto, nullptr, range-based for, 참조/포인터, const
실습: 벡터 순회, const 함수 vs 비const 함수

1. 햅과 스택의 구분
2. 포인터
3. nullptr
4. const 의 구분
5. mutable 
6. auto 과 range_based for 를 활용한 문제풀이
https://school.programmers.co.kr/learn/courses/30/lessons/42576
---

✅ 2강. 컨테이너 핵심 - vector, string, array
목표: 주요 선형 자료구조 마스터
핵심: vector, string, array, 크기 조절, 반복자
실습: 부분합, 문자열 조작, 동적 벡터 관리

---

✅ 3강. STL 알고리즘으로 문제 해결하기 (LINQ 대응 집중)
목표: 선언형 스타일 STL 알고리즘 이해 및 활용
핵심: sort, find_if, count_if, copy_if, accumulate, iota
C# LINQ과의 대응:

  
where → copy_if
select → transform (기초 소개)
aggregate → accumulate
orderBy → sort
실습: 조건부 합산, 필터링, 중복 제거

---

✅ 4강. map, set, unordered_map 활용법
목표: 키-값 자료구조 이해 및 적용
핵심: map vs unordered_map, set, 키 존재 확인, 삽입/삭제
실습: 빈도수 세기, 중복 제거, 정렬 순회 비교

---

✅ 5강. 스마트 포인터 & 메모리 모델 이해
목표: 안전한 동적 메모리 관리
핵심: unique_ptr, shared_ptr, weak_ptr, make_unique/shared
C# GC 및 참조 모델 비교
실습: 동적 객체 생성, 소멸 타이밍 추적, 복사 방지

---

✅ 6강. l-value / r-value 참조 & 이동语义
목표: Modern C++의 핵심 표현력 이해
핵심: l-value, r-value, std::move, std::forward
이동 생성자와 이동 대입자 간략 소개
실습: 이동语义 적용 예제

---

✅ 7강. 표현력을 높이는 Modern C++ 도구
목표: 고급 함수형 스타일 및 다중 반환 처리
핵심:

  
함수 객체(Functor)와 operator()
std::function과 타입 소거
std::transform, std::for_each (함수 객체와의 조합 맥락에서만)
구조적 바인딩, std::pair, std::tuple
std::optional (기본 개념)
실습:

  
Functor로 조건 처리
std::function에 람다/함수 객체 대입
transform + 함수 객체 조합
구조적 바인딩으로 다중 값 분해
optional 활용 기본
