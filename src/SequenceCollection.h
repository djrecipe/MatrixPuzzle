#pragma once
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Path.h"
#include "Sequence.h"
#include "SequenceCollectionResult.h"
class SequenceCollection
{
public:
    SequenceCollection(std::vector<Sequence> sequences_in);
    void ClearAttempted();
    bool GetAnyAttemptsRemain();
    bool GetAllUncompleted();
    bool GetAlreadyAttemptedOrCompleted(Sequence sequence);
    std::optional<Sequence> GetLastCompletedSequence();
    int GetLastStartIndex();
    std::optional<Sequence> GetNextUnattempted();
    SequenceCollectionResult GetResult();
    std::size_t GetSolutionLength();
    void ResetSuboptimalCompletions();
    void SetAttempted(Sequence sequence);
    void SetCompleted(Sequence sequence);
    void SetFinalPath(Path path);
    std::vector<Sequence> sequences;
private:
    Path finalPath;
    std::unordered_set<std::size_t> attempted;
    std::unordered_set<std::size_t> completed;
    std::optional<Sequence> lastCompletedSequence;
    std::unordered_map<std::size_t, int> sequence_start_index;
    std::unordered_map<std::size_t, int> completion_lengths;
};

