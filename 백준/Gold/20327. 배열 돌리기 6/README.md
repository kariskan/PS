# [Gold III] 배열 돌리기 6 - 20327 

[문제 링크](https://www.acmicpc.net/problem/20327) 

### 성능 요약

메모리: 2088 KB, 시간: 52 ms

### 분류

구현(implementation), 시뮬레이션(simulation)

### 문제 설명

<p>크기가 2<sup>N</sup>×2<sup>N</sup>인 배열이 있을 때, 배열에 연산을 R번 적용하려고 한다. 연산은 8가지가 있고, 연산에는 단계 ℓ (0 ≤ ℓ < N)이 있다. 단계 ℓ은 배열을 부분 배열로 나눌때 사용하는 값이며, 부분 배열의 크기는 2<sup>ℓ</sup>×2<sup>ℓ</sup>가 되어야 한다. 단계는 연산을 수행할때마다 정한다.</p>

<p>다음은 크기가 2<sup>3</sup>×2<sup>3</sup> 배열을 단계 ℓ의 값에 따라 부분 배열로 나눈 것이다. 같은 부분 배열은 같은 색상으로 표시했다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:33%;"><img alt="" src="https://upload.acmicpc.net/f24cff71-7497-4787-b7f3-a9d078b34838/-/preview/" style="width: 200px; height: 201px;"></td>
			<td style="width:34%;"><img alt="" src="https://upload.acmicpc.net/b1a58aab-4244-40a9-bc79-2c94e2b2d123/-/preview/" style="width: 200px; height: 201px;"></td>
			<td style="width:33%;"><img alt="" src="https://upload.acmicpc.net/4cf863ff-01e5-4556-a915-1cd0e9d1cebb/-/preview/" style="width: 200px; height: 201px;"></td>
		</tr>
		<tr>
			<th>ℓ = 0</th>
			<th>ℓ = 1</th>
			<th>ℓ = 2</th>
		</tr>
	</tbody>
</table>

<p>1번 연산은 각 부분 배열을 상하 반전시키는 연산이다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/80ecb0fd-aaf3-479a-9d56-8d2eb171faa3/-/preview/" style="width: 250px; height: 251px;"></td>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/ad7ac698-343b-4c83-b13e-b6b2f5ec0e44/-/preview/" style="width: 250px; height: 251px;"></td>
		</tr>
		<tr>
			<th>배열</th>
			<th>ℓ = 1, 1번 연산 적용</th>
		</tr>
	</tbody>
</table>

<p>2번 연산은 각 부분 배열을 좌우 반전시키는 연산이다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/da983352-287c-4b02-a980-bfb6274ffed4/-/preview/" style="width: 250px; height: 251px;"></td>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/a2b0c85a-9628-4f02-8702-0b79b354b80d/-/preview/" style="width: 250px; height: 251px;"></td>
		</tr>
		<tr>
			<th>배열</th>
			<th>ℓ = 2, 2번 연산 적용</th>
		</tr>
	</tbody>
</table>

<p>3번 연산은 각 부분 배열을 오른쪽으로 90도 회전시키는 연산이다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/42372266-c8c2-4a69-8ea4-5ef2998edb22/-/preview/" style="width: 250px; height: 251px;"></td>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/344b458d-42b3-40d6-a47b-f458c2a3d9b2/-/preview/" style="width: 250px; height: 251px;"></td>
		</tr>
		<tr>
			<th>배열</th>
			<th>ℓ = 1, 3번 연산 적용</th>
		</tr>
	</tbody>
</table>

<p>4번 연산은 각 부분 배열을 왼쪽으로 90도 회전시키는 연산이다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/7e3bdcc1-b486-47d9-89b1-5ebbc53cb5a2/-/preview/" style="width: 250px; height: 251px;"></td>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/6ed7d1ec-c8cf-415e-b9b1-7d862e530578/-/preview/" style="width: 250px; height: 251px;"></td>
		</tr>
		<tr>
			<th>배열</th>
			<th>ℓ = 2, 4번 연산 적용</th>
		</tr>
	</tbody>
</table>

<p>5, 6, 7, 8번 연산은 부분 배열을 한 칸으로 생각하고 적용시킨다. 즉, 부분 배열의 안에 있는 값은 변하지 않는다.</p>

<p>5번 연산은 배열을 상하 반전시키는 연산이다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/fc167739-a773-4999-b539-e415dca2460d/-/preview/" style="width: 250px; height: 251px;"></td>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/4c185ecd-0e68-4cd2-88d9-5b79253970f8/-/preview/" style="width: 250px; height: 251px;"></td>
		</tr>
		<tr>
			<th>배열</th>
			<th>ℓ = 2, 5번 연산 적용</th>
		</tr>
	</tbody>
</table>

<p>6번 연산은 배열을 좌우 반전시키는 연산이다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/97f4a416-def3-4f54-b9c8-e8f065c3cdb8/-/preview/" style="width: 250px; height: 251px;"></td>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/e626a283-8e42-4cfd-bb88-162eddff248f/-/preview/" style="width: 250px; height: 251px;"></td>
		</tr>
		<tr>
			<th>배열</th>
			<th>ℓ = 1, 6번 연산 적용</th>
		</tr>
	</tbody>
</table>

<p>7번 연산은 오른쪽으로 90도 회전시키는 연산이다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/10084e04-eb44-4973-96ae-9b8e6f677f4b/-/preview/" style="width: 250px; height: 251px;"></td>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/73d646d9-8368-4f87-834f-85b420e18960/-/preview/" style="width: 250px; height: 251px;"></td>
		</tr>
		<tr>
			<th>배열</th>
			<th>ℓ = 1, 7번 연산 적용</th>
		</tr>
	</tbody>
</table>

<p>8번 연산은 왼쪽으로 90도 회전시키는 연산이다.</p>

<table class="table table-bordered td-center th-center" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/fd814d8a-0009-411d-9a41-b2a5a1ad7545/-/preview/" style="width: 250px; height: 251px;"></td>
			<td style="width:50%;"><img alt="" src="https://upload.acmicpc.net/51d21c8f-46e7-491f-ad5c-9669226023e5/-/preview/" style="width: 250px; height: 251px;"></td>
		</tr>
		<tr>
			<th>배열</th>
			<th>ℓ = 2, 8번 연산 적용</th>
		</tr>
	</tbody>
</table>

### 입력 

 <p>첫째 줄에 N, R이 주어진다. 둘째 줄부터 2<sup>N</sup>개의 줄에 배열의 원소 A[i][j]가 주어진다. i번째 줄의 j번째 정수는 A[i][j]를 의미한다.</p>

<p>다음 R개의 줄에 배열에 적용시켜야 하는 연산이 한 줄에 하나씩 주어진다. 연산은 두 정수 k, ℓ로 이루어져 있고, k번 연산을 단계 ℓ로 적용한다는 의미이다.</p>

### 출력 

 <p>입력으로 주어진 배열에 R개의 연산을 순서대로 수행한 결과를 출력한다.</p>

