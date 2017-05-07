#include "LowPassFilter.hpp"
#include <stdlib.h>

LowPassFilter::LowPassFilter(unsigned int samplesCapacity) :
  m_SamplesCount(0),
  m_SamplesCapacity(samplesCapacity)
{
  m_pSamples = (float*)malloc (samplesCapacity * sizeof(float));
}

LowPassFilter::~LowPassFilter()
{
  free(m_pSamples);
}

float LowPassFilter::run(float sample)
{
  if(++m_SamplesCount > m_SamplesCapacity)
  {
    m_SamplesCount = m_SamplesCapacity;
  }

  float output = sample;
  m_pSamples[m_SamplesCount - 1] = sample;
  for(unsigned int i = 0; i < m_SamplesCount - 1; i++)
  {
    output += m_pSamples[i];
    m_pSamples[i] = m_pSamples[i + 1];
  }
  return output / m_SamplesCount;
}
