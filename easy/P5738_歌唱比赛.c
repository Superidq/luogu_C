// Created by Glin on 2023/5/18.
#include "stdio.h"

int main(){
    int n_students = 0;
    int m_scores = 0;
    int scores[20] = {0};
    double max = 0.0;
    scanf("%d %d", &n_students, &m_scores);
    for (int i = 0; i < n_students; ++i) {
        for (int j = 0; j < m_scores; ++j) {
            scanf("%d", &scores[j]);
        }
        int min_s = scores[0];
        int max_s = scores[0];
        int sum_s = 0;
        for (int j = 0; j < m_scores; ++j) {
            if(min_s > scores[j])
                min_s = scores[j];
            if(max_s < scores[j])
                max_s = scores[j];
            sum_s += scores[j];
        }
        sum_s = sum_s - min_s - max_s;
        double average = sum_s*1.0 / (m_scores-2);
        if(i == 0)
            max = average;
        else if(max < average)
            max = average;
    }
    printf("%.2lf", max);

    return 0;
}