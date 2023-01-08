#include <stdio.h>
char a[2017][50] = { 0, };
struct album {
	int year;
	char* title;
};
int main() {
	struct album a[26] = { 1967,"DavidBowie", 1969 ,"SpaceOddity",
1970, "TheManWhoSoldTheWorld",
1971, "HunkyDory",
1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
1973 ,"AladdinSane",
1973, "PinUps",
1974, "DiamondDogs",
1975 ,"YoungAmericans",
1976, "StationToStation",
1977 ,"Low",
1977, "Heroes",
1979 ,"Lodger",
1980, "ScaryMonstersAndSuperCreeps",
1983, "LetsDance",
1984, "Tonight",
1987, "NeverLetMeDown",
1993, "BlackTieWhiteNoise",
1995, "1.Outside",
1997, "Earthling",
1999 ,"Hours",
2002, "Heathen",
2003 ,"Reality",
2013, "TheNextDay",
2016, "BlackStar" };
	int n;
	scanf("%d", &n);
	int s, e;
	for (int i = 0; i < n; i++) {
		int count = 0;
		scanf("%d %d", &s, &e);
		for (int j = 0; j < 26; j++) {
			if (a[j].year >= s && a[j].year <= e) count++;
		}
		printf("%d\n", count);
		for (int j = 0; j < 26; j++) {
			if (a[j].year >= s && a[j].year <= e) printf("%d %s\n", a[j].year, a[j].title);
		}
	}
}