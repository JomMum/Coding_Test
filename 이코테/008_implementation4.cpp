#include <iostream>
#include <string>
#include <algorithm>

//문자열 재정렬
int main() {
  std::string answer;
  std::string result;
  
  int numResult = 0;
  std::string strResult = "";

  //문자열 받아오기
  std::cin >> answer;

  for(int i=0; i<answer.size(); i++) {
    //만약 해당 문자가 숫자값일 시 더한 값을 저장
    if(answer[i] - '0' >= 0 &&
       answer[i] - '0' <= 9) {
        numResult += answer[i] - '0';
    }
    //만약 해당 문자가 문자값일 시 따로 저장
    else {
      strResult += answer[i];
    }
  }

  //문자열 정렬
  std::sort(strResult.begin(), strResult.end());

  //결과값 출력
  if(numResult != 0) //숫자값이 있을 시 맨 뒤에 출력
    result = strResult + std::to_string(numResult);
  else //숫자값이 없을 시 문자열만 출력
    result = strResult;
  
  std::cout << result;
}