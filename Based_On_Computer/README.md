SVM을 이용하여, 선글라스 영역 검출하기

1.현재 진행 중인 부분

train_data.cpp 에서 .xml 파일 읽어오는데 오류나는건지

SVM_create함수에서 Ptr<ml::SVM> 객체 선언하는데 오류나는건지 모르겠음 



2.학습이미지 정보 .png

이미지 비율 2.5 : 1 

픽셀 사이즈 200 : auto

0~34 선글라스 이미지

35~69 선글라스아닌 이미지 




3. 참고) 트레이닝 데이터 만들 때

그림판으로 픽셀 크기나 비율 수정하려고 하면 투명배경에서 흰색 배경 생김. 

아래 사이트에서 수정하면 편함

https://www.iloveimg.com/ko/crop-image
