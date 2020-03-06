

#include "indexing.h"


void PHHSIndex::on(float speed)
{
    m_indexingmotor1.Set(speed);
    m_indexingmotor2.Set(speed);
    m_indexingmotor3.Set(speed);
}

void PHHSIndex::off(float speed)
{
    m_indexingmotor1.Set(speed);
    m_indexingmotor2.Set(speed);
    m_indexingmotor3.Set(speed);
}