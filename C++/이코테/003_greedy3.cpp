#include <iostream>
#include <string>

//곱하기 혹은 더하기
int main() {
  std::string num = "567";
  int result = 0;

  result = num[0] - '0';

  for (int i = 1; i < num.length(); i++)
  {
    //현재 연산될 숫자
    int curNum = num[i] - '0';

    //만약 곱했을 때 값이 더 클 경우
    if (result * curNum > result + curNum) 
    {
      result *= curNum; //곱한다
    }
    //더했을 때 값이 더 클 경우
    else 
    {
      result += curNum; //더한다
    }
  }

  std::cout << result;
}