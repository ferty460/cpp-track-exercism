#include <array>
#include <string>
#include <vector>

std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_scores;

    for (double score : student_scores) {
        rounded_scores.push_back(static_cast<int>(score));
    }

    return rounded_scores;
}

int count_failed_students(std::vector<int> student_scores) {
    int count = 0;

    for (int i = 0; i < student_scores.size(); i++) {
        if (student_scores[i] <= 40) {
            count++;
        }
    }

    return count;
}

std::array<int, 4> letter_grades(int highest_score) {
    int range = highest_score - 40;
    double interval = range / 4;

    int D = 41;
    int C = D + static_cast<int>(interval);
    int B = C + static_cast<int>(interval);
    int A = B + static_cast<int>(interval);

    return {D, C, B, A};
}

std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> result;

    for (int i = 0; i < student_scores.size(); i++) {
        result.push_back(
            std::to_string(i + 1) + ". " +
            student_names[i] + ": " +
            std::to_string(student_scores[i])
        );
    }

    return result;
}

std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    int index = 0;

    for (int i = 0; i < student_scores.size(); i++) {
        if (student_scores[i] == 100) {
            index = i;
            break;
        }
    }

    return (index == 0 ? "" : student_names[index]);
}
