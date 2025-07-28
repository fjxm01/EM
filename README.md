**EM 기법 사용법**

1. 입력 형태
  - 입력: PCL의 Type PointXYZ를 입력
  
2. 옵션 설정
  - gmm(num_clusters, viz, max_iters, tol)
  - num_clusters: 클러스터를 몇개 생성시킬 것인가?
  - viz: 실행 과정을 시각화 할 것인가? (기본: false)
  - max_iters: 최대 반복 횟수 (기본: 200번)
  - tol: 최소 에러양 (기본: 1e-3)

3. 함수 사용
  - ExpectationMaximization gmm(2, true) 선언 후 gmm.run(cloud)를 싱행한다.
    
<img width="962" height="572" alt="image" src="https://github.com/user-attachments/assets/03324bb6-a3be-456a-b68b-dcb6fe952e68" />

**EM 기법 설명**

정의)

관측되지 않은 데이터가 있을 때 전체 데이터의 가능도를 최대화하는 파라미터를 추정하는 것

알고리듬 순서)

[STEP 1] 평균, 공분산, 사전 확률을 포기화 한다. 

<img width="873" height="143" alt="image" src="https://github.com/user-attachments/assets/8d40932a-2dbc-478e-9a6c-0029a721def1" />

[STEP 2] 각 Point Cloud 데이터가 어떤 클러스터에 포함되는지에 대한 확률을 구한다. 

<img width="533" height="339" alt="image" src="https://github.com/user-attachments/assets/67d57565-5353-4fe9-9ee0-2722f5844b31" />

[STEP 3] E-step에서 계산한 확률을 바탕으로 parameter를 업데이트하여 전체 데이터의 likelihood를 최대화한다.

<img width="659" height="330" alt="image" src="https://github.com/user-attachments/assets/ceb463b3-4a6d-454d-904c-435cf2e88c55" />

[STEP 4] 두 가지 종료 조건 중 하나라도 성립한다면 종료한다.  

<img width="1190" height="111" alt="image" src="https://github.com/user-attachments/assets/8bdee5b0-ddf3-4412-8dbb-497526ffbbd6" />

