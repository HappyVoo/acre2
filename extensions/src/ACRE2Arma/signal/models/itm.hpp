#ifndef ACRE2ARMA_SIGNAL_MODELS_ITM_HPP_
#define ACRE2ARMA_SIGNAL_MODELS_ITM_HPP_

#include <cmath>
#include <complex>
#include <cassert>
#include <algorithm>

#include "models_common.hpp"
#include "../antenna/antenna.hpp"

#include <map>

namespace acre {
    namespace signal {
        namespace model {
            class itm : public SignalModel {
            public:
                itm() {};
                itm(map_p map);
                ~itm();

                void process(result *const result, const glm::vec3 &tx_pos, const glm::vec3 &tx_dir, const glm::vec3 &rx_pos, const glm::vec3 &rx_dir, const antenna_p &tx_antenna, const antenna_p &rx_antenna, const float32_t frequency, const float32_t power, const float32_t scale, const bool omnidirectional, const bool useClutterAttenuation);
            protected:
                typedef enum {
                    acre_itmPropagation_los,
                    acre_itmPropagation_diffraction,
                    acre_itmProgatagion_troposcatter
                } acre_itmPropagation_t;
            };
        }
    }
}

#endif /* ACRE2ARMA_SIGNAL_MODELS_ITM_HPP_ */
