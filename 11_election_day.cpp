#include <string>
#include <vector>

namespace election {

    struct ElectionResult {
        std::string name{};
        int votes{};
    };

    int vote_count(ElectionResult& er) {
        return er.votes;
    }

    void increment_vote_count(ElectionResult& er, int votes) {
        er.votes += votes;
    }

    ElectionResult& determine_result(std::vector<ElectionResult>& results) {
        int max_votes = results[0].votes;
        int index = 0;

        for (int i = 1; i < results.size(); i++) {
            if (results[i].votes > max_votes) {
                max_votes = results[i].votes;
                index = i;
            }
        }

        results[index].name = "President " + results[index].name;

        return results[index];
    }

}