#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "stats.h"
#include "search.h"

void creat_list(char name[])
{
	int i;
	int point1;
	int point2;
	int weight;
	Adj *s;
	for (i = 0; i < MAXSIZE1; i++) {
		G[i].next = NULL;
	}
	for (i = 0; i < MAXSIZE2; i++) {
		location[i] = -1;
	}
	freopen(name, "r", stdin);
	while (scanf("%d %d %d", &point1, &point2, &weight) != EOF) {
		if (location[point1] == -1) {
			G[num_point].code = point1;
			location[point1] = num_point;
			num_point++;
		}
		s = (Adj*)malloc(sizeof(Adj));
		s->code = point2;
		s->weight = weight;
		s->next = G[location[point1]].next;
		G[location[point1]].next = s;
		if (location[point2] == -1) {
			G[num_point].code = point2;
			location[point2] = num_point;
			num_point++;
		}
	}
	fclose(stdin);
}

void init(Queue *Q)
{
	Q->rear = -1;
	Q->front = -1;
}

void enqu(Queue *Q, int code)
{
	Q->rear++;
	Q->data[Q->rear] = code;
}

int dequ(Queue *Q)
{
	Q->front++;
	return Q->data[Q->front];
}

int empty_qu(Queue *Q)
{
	if (Q->front == Q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

void picture()
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@00..0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@00..0000\\.00@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@\\@@@@@@@@@0.,0@@@@@@@@0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@.|@@@@@@@0.,0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@.||..0@@0..0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@,.,@@@''@@@00.   00@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@ .  . . @@@@. .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@.        @@ .  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@.          @    .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@.          @    .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@.           .      .@@@@@@@@@@@@@@@__@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@.                     .@@@@@@@@@@@@/  \\@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@.                         .@@@@@@@@@/  | \\@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@.         __       __           .@@@@/  /@\\ \\@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@.         /  \\     /  \\           ./  /@@@\\  \\@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@.           .\\__/     \\__/            .  @@@@ \\  \\@@@@@@@@@\n");
	printf("@@@@@@@@@@@.           .                            .@@@@@@     @@@@@@@@@\n");
	printf("@@@@@@@@@@@@.          .                            .@@@@@@       @@@@@@@\n");
	printf("@@@@@@@@@@@/  .           .                         .@@@@@@@@@    @@@@@@@\n");
	printf("@@@@@@@@@@/\\           .   \\_______/           /@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@/  /@@@\\.           .                   .@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@/  |@@@@@\\.           .               ./@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@/  /@@@@| .           .            .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@/  /@@@@@@|.           .         .\\   /@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@       @@@@@@|  /@.           .      .@@@\\  |@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@     @@@@@@/  /@.           .      .@@@@\\ \\.@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@/  /@@@@@@@@@@@@@@@@@@@@@@@@@@@\\ \\.@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@/  /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|  |.@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@|  |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\\ \\@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@______/  |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|  |_____@@@@@@@@@@@@@@\n");
	printf("@@@@@@@|         |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|        |@@@@@@@@@@@@@\n");
	printf("@@@@@@@\\_______|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@________|@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

char* self_strcat(char *str, char *str2)
{
	char* str1 = str;
	while (*str1 != '\0') {
		str1++;
	}
	while (*str2 != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str;
}
