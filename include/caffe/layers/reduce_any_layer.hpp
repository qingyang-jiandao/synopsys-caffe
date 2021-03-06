#ifndef CAFFE_REDUCE_ANY_LAYER_HPP_
#define CAFFE_REDUCE_ANY_LAYER_HPP_

#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

namespace caffe {

template <typename Dtype> class ReduceAnyLayer : public Layer<Dtype> {
public:
  explicit ReduceAnyLayer(const LayerParameter &param) : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype> *> &bottom,
                          const vector<Blob<Dtype> *> &top);
  virtual void Reshape(const vector<Blob<Dtype> *> &bottom,
                       const vector<Blob<Dtype> *> &top);

  virtual inline const char *type() const { return "ReduceAny"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

protected:
  virtual void Forward_cpu(const vector<Blob<Dtype> *> &bottom,
                           const vector<Blob<Dtype> *> &top);
  /// @brief Not implemented
  virtual void Backward_cpu(const vector<Blob<Dtype> *> &top,
                            const vector<bool> &propagate_down,
                            const vector<Blob<Dtype> *> &bottom) {
    NOT_IMPLEMENTED;
  }

  inline vector<int> indices(int offset, const vector<int> &shape) const;
  inline int offset(const vector<Blob<Dtype> *> &bottom,
                    const vector<int> &axis_ind,
                    const vector<int> &indices) const;

  vector<int> axis_;
  bool keepdims_;
  int axis_dim_;
};

} // namespace caffe

#endif // CAFFE_REDUCE_ANY_LAYER_HPP_
