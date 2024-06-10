# [Gold II] 부품 대여장 - 21942 

[문제 링크](https://www.acmicpc.net/problem/21942) 

### 성능 요약

메모리: 12332 KB, 시간: 296 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 구현, 파싱, 문자열

### 제출 일자

2024년 6월 10일 11:29:10

### 문제 설명

<p>송훈이는 로봇 동아리 회원이다. 로봇 동아리에서 필요한 부품이 있을 경우 자유롭게 빌려서 쓰고 다시 돌려놓으면 된다.</p>

<p>하지만 부품 정리를 하다가 부품 관리가 너무 힘들어져 새로운 시스템을 도입하려고 한다.</p>

<p>부품을 빌려갈 경우 <strong>부품 대여장</strong>에 정보를 반드시 작성해야한다. 또한 빌려간 부품을 반납 할 경우에도 <strong>부품 대여장</strong>에 정보를 작성해야한다.</p>

<p>또한 대여기간을 정하고 대여기간을 넘길 경우 1분당 벌금을 부여하도록 하는 시스템이다.</p>

<p>만약 대여기간이 5분, 1분당 벌금이 5원이라 했을 때 대여한 시각이 <strong>2021년 1월 1일 1시 5분</strong>이라면 <strong>2021년 1월 1일 1시 10분까지</strong> 반납해야한다.</p>

<p><strong>2021년 1월 1일 1시 14분</strong>에 반납을 했다면 4분 늦었기 때문에 벌금을 20원을 내야한다.</p>

<p>부품 대여장에 쓰는 형식은 아래와 같다.</p>

<pre>yyyy-MM-dd hh:mm [부품 이름] [동아리 회원 닉네임]</pre>

<p>아래는 예시를 위한 부품 대여장에 작성된 정보이다. 대여기간이 5분, 벌금은 1원이라 가정하자.</p>

<pre>2021-01-01 09:12 arduino tony9402
2021-01-01 09:13 monitor chansol
2021-01-01 09:18 arduino tony9402
2021-01-01 09:18 monitor chansol</pre>

<p>위의 정보를 정리하면 아래와 같다.</p>

<pre>tony9402가 2021년 1월 1일 오전 9시 12분에 arduino를 빌렸다.
chansol이 2021년 1월 1일 오전 9시 13분에 monitor를 빌렸다.
tony9402가 2021년 1월 1일 오전 9시 18분에 arduino를 반납했다.
chansol이 2021년 1월 1일 오전 9시 18분에 monitor를 반납했다.</pre>

<p>tony9402는 1분 늦게 반납했기 때문에 벌금 1원을 내야한다.</p>

<p>부품을 대여할 때 지켜야 하는 조건이 있다.</p>

<ol>
	<li>한 사람이 같은 종류의 부품을 두개 이상 대여하고 있는 상태일 수 없다.</li>
	<li>한 사람이 같은 시각에 서로 다른 종류의 부품들을 대여하는 것이 가능하다.</li>
	<li>같은 사람이더라도, 대여 기간은 부품마다 별도로 적용된다.</li>
</ol>

### 입력 

 <p>첫 번째 줄에 부품 대여장에 작성된 정보의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>, 대여기간 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$L$</span></mjx-container>, 벌금 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D439 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>F</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$F$</span></mjx-container>이 공백으로 구분되어 주어진다.</p>

<p>대여기간 형식은 <code>DDD/hh:mm</code>으로 <code>DDD</code>는 일, <code>hh</code>는 시간, <code>mm</code>은 분을 의미한다. (<code>000/00:00</code> 는 주어지지 않는다.)</p>

<p>두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>+</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N + 1$</span></mjx-container>번째 줄까지 <strong>시간순</strong>으로 부품 대여장에 작성한 정보 (시각, 부품 이름 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container>, 회원 닉네임 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>)이 공백으로 구분되어 주어진다.</p>

<p>빌린 시각의 형식은 <code>yyyy-MM-dd hh:mm</code>으로 <code>yyyy</code>는 연도, <code>MM</code>는 월, <code>dd</code>는 일, <code>hh</code>는 시간, <code>mm</code>는 분을 의미한다. 이 문제에서 들어오는 연도는 항상 2021년도이다.</p>

<p>부품 이름 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container>는 알파벳 소문자로만 이루어져 있다. 즉, 부품 이름에 공백이 없다.</p>

<p>회원 닉네임 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>은 알파벳 소문자와 숫자<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(0$</span></mjx-container> ~ <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>9</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$9)$</span></mjx-container>로만 이루어져있다. 즉, 회원 닉네임에 공백이 없다.</p>

### 출력 

 <p>벌금을 내야하는 사람들을 <strong>사전순</strong>으로 동아리 회원 닉네임 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>와 내야하는 벌금을 한 줄씩 출력한다.</p>

<p>만약 벌금을 내야하는 사람들이 없는 경우는 -1을 출력한다.</p>

