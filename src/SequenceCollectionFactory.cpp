#include "SequenceCollectionFactory.h"

std::vector<SequenceCollection> SequenceCollectionFactory::GenerateUniqueSequenceCollections(std::vector<Sequence> sequences)
{
    std::vector<int> permutations;
    for (int i = 0; i < sequences.size(); i++)
        permutations.push_back(i);
    std::vector<SequenceCollection> collection_vec;
    do
    {
        std::vector<Sequence> sequence_perm;
        for (int i = 0; i < permutations.size(); i++)
            sequence_perm.push_back(sequences[permutations[i]]);
        auto collection = SequenceCollection(sequence_perm);
        collection_vec.push_back(collection);
    }
    while (next_permutation(permutations.begin(), permutations.end()));
    return collection_vec;
}