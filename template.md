# 문제 분석

## 문제

5653 줄기세포 배양

## 출처

SWEA [link](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo)

## 문제 요약

* 초기 상태에서 줄기 세포들이 시간이 지나며 번식하거나 죽게 됨
* 용기의 크기는 무한

## 문제 유형

* 시뮬레이션
* BFS

## 어려운 점

* 용기의 크기가 무한함
* 동시 번식하려는 경우 생명력 수치가 높은 세포가 셀을 차지

## 해결 과정

* 초기 그리드 크기가 50x50이고, 각 셀의 생명령이 1이라고 해도 2시간에 한번씩 번식하기 때문에 상하좌우로 최대 150씩 더 커질 수 있음
* 초기 세포 좌표를 500x500 크기로 매핑해서 풀면 됨
* spawn, alive 벡터를 두고 spawn을 생명력 수치로 정렬하여 풀었음
