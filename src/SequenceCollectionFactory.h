#pragma once
#include <vector>
#include "SequenceCollection.h"
class SequenceCollectionFactory
{
public:
    std::vector<SequenceCollection> GenerateUniqueSequenceCollections(std::vector<Sequence> sequences);
};

