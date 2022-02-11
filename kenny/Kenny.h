#pragma once

#include "src/VertexMat.h"
#define KENNYDATASIZE 19

namespace kenny
{
    enum class part
    {
        
    };

    class Kenny
    {
    private:
        spat::PosSizeData m_QuardPS[KENNYDATASIZE];
        spat::PosSizeData m_TexPS[KENNYDATASIZE];
    public:
        Kenny();
        ~Kenny();
        spat::PosSizeData GetQuardPS(int i) const {return m_QuardPS[i];}
        spat::PosSizeData GetTexPS(int i) const {return m_TexPS[i];}
        int GetDataSize() {return (int)KENNYDATASIZE;}
    };

}