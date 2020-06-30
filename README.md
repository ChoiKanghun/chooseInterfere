내가 짠 코드보다 더 예쁘게 짠 rchallie의 코드를 수도코드로 만들어봄. <br>
https://42kchoi.tistory.com/153 
<br>
참고할만한 test case 
(코드 안의 내용을 repo root에 복사해서 붙여넣으면 됨.)
<br>
1. https://github.com/cclaude42/PFT_2019
<br>
```
git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp

Make

./test
```
<br>
-> 744 430 431 130   빼고 모두 패스.
<br>
2. https://github.com/gavinfielder/pft
<br>
```
git clone https://github.com/gavinfielder/pft.git pft && echo "pft/" >> .gitignore

Make

./test

```
<br>
-> 4192 4193 4194 647 497 빼고 올 패스
<br>
rchallie github - https://github.com/rchallie/ft_printf
