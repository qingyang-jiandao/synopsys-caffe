#ifndef CAFFE_THRESHOLDED_RELU_LAYER_HPP_
#define CAFFE_THRESHOLDED_RELU_LAYER_HPP_

#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

#include "caffe/layers/neuron_layer.hpp"

namespace caffe {

// implement of ONNX Operator:
// https://github.com/onnx/onnx/blob/master/docs/Operators.md#thresholdedrelu

template <typename Dtype>
class ThresholdedReLULayer : public NeuronLayer<Dtype> {
public:
  explicit ThresholdedReLULayer(const LayerParameter &param)
      : NeuronLayer<Dtype>(param) {}

  virtual inline const char *type() const { return "ThresholdedReLU"; }

protected:
  virtual void Forward_cpu(const vector<Blob<Dtype> *> &bottom,
                           const vector<Blob<Dtype> *> &top);
  virtual void Backward_cpu(const vector<Blob<Dtype> *> &top,
                            const vector<bool> &propagate_down,
                            const vector<Blob<Dtype> *> &bottom) {
    for (int i = 0; i < propagate_down.size(); ++i) {
      if (propagate_down[i]) {
        NOT_IMPLEMENTED;
      }
    }
  }
};

} // namespace caffe

#endif // CAFFE_THRESHOLDED_RELU_LAYER_HPP_
