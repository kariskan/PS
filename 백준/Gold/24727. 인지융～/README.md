# [Gold III] 인지융~ - 24727 

[문제 링크](https://www.acmicpc.net/problem/24727) 

### 성능 요약

메모리: 2240 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 6월 28일 23:18:48

### 문제 설명

<p>연세대학교는 2022년부터 인공지능융합대학이라는 단과대를 새로 만들고, 기존 공과대학 소속이었던 컴퓨터과학과를 해당 단과대로 보내버렸다. 하지만 아직 인공지능융합대학 건물이 지어지지 않았기 때문에, 학생들은 여전히 공학관을 사용하고 있다.</p>

<p>이에 공과대학의 다른 학과 학생들이 컴퓨터과학과 학생들을 놀리기 시작했다!</p>

<p>화가 난 컴퓨터과학과 학생들은 바리케이드를 쳐 다른 공과대학 학생들이 접근하지 못하게 하였다. 하지만 실수로 다른 학과의 공간을 침범해 버려, 성난 학생들과 교수님들이 바리케이드를 부숴버렸다!</p>

<p>결국 긴 시간의 협상 끝에, 공과대학 측이 필요한 공간의 크기와 컴퓨터과학과가 필요한 공간의 크기를 미리 제출한 후, 각각 크기를 보장하면서 바리케이드를 치기로 합의하였다.</p>

<p>공학관은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times N$</span></mjx-container> 크기의 정사각형 모양이고, 바리케이드를 친 이후 컴퓨터과학과의 공간과 공과대학 측의 공간은 연결되어 있지 않아야 하나, 각자의 공간은 모두 연결되어 있어야 한다.</p>

<p>여기서 "연결"이라 함은, 어떤 공간이 상하좌우로 인접해 있는 것을 말한다.</p>

<p>예를 들어, 다음 그림에서 왼쪽의 경우 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A$</span></mjx-container>공간과 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>공간은 연결되어 있지 않다고 볼 수 있으며, 오른쪽의 경우 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A$</span></mjx-container>공간과 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>공간이 연결되었다고 볼 수 있다.</p>


<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/131c5e52-3ae0-4cb0-ab1b-8188f3684a6a/-/preview/" width="650px"></p>

<p>또한, 싸움이 나는 것을 방지하기 위해 정확히 제출한 크기만큼의 공간만 제공되어야 한다.</p>

<p>공학관의 크기와 컴퓨터과학과, 공과대학 측이 제출한 공간의 크기가 주어졌을 때, 어떤 식으로 공간을 나눠야 할지 구해보자.</p>

### 입력 

 <p>첫 줄에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> 이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 \le N \le 100)$</span> </mjx-container></p>

<p>두 번째 줄에는 컴퓨터과학과가 필요한 공간의 크기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>C</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$C$</span></mjx-container>, 다른 공과대학 학과들이 필요한 공간의 크기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D438 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>E</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$E$</span></mjx-container>가 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D438 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: 0.363em; margin-left: 0.054em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>C</mi><mo>,</mo><mi>E</mi><mo>≤</mo><msup><mi>N</mi><mn>2</mn></msup><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 \le C, E \le N ^ 2)$</span> </mjx-container></p>

### 출력 

 <p>주어진 조건을 맞춰 공간을 나눌 수 없다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

<p>주어진 조건을 맞춰 공간을 분할할 수 있다면, 첫 줄에 <span style="color:#e74c3c;"><code>1</code></span>을 출력한다. 또한, 두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>줄에 걸쳐 공간을 나눈 결과를 출력한다. 여기서 <span style="color:#e74c3c;"><code>1</code></span>은 컴퓨터과학과의 공간, <span style="color:#e74c3c;"><code>2</code></span>는 공과대학의 공간이며, <code><span style="color:#e74c3c;">0</span></code>은 바리케이드다.</p>

