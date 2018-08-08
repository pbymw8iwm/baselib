/// @file batch_sequence.h

#ifndef BATCH_SEQUENCE_H
#define BATCH_SEQUENCE_H

#include <cstddef>

namespace utils
{
    /// 分批序列化序列
    template <typename Sequence>
    class batch_sequence
    {
    public:
        typedef typename Sequence::value_type value_type;
        typedef typename Sequence::iterator iterator;

        batch_sequence(Sequence & seq)
            : seq_(seq)
            , i_(seq.begin())
            , remain_(seq.size())
        {
        }

        void reset()
        {
            i_ = seq_.begin();
            remain_ = seq_.size();
        }

        value_type & current()
        {
            assert(i_ != seq_.end());
            return *i_;
        }

        value_type const & current() const
        {
            assert(i_ != seq_.end());
            return *i_;
        }

        void next() const
        {
            ++i_;
            remain_--;
        }

        std::size_t size() const
        {
            return seq_.size() - remain_;
        }

        std::size_t capcity() const
        {
            return seq_.size();
        }

        void reserve(std::size_t n) const
        {
            if (remain_ < n) {
                seq_.resize(seq_.size() + n - remain_);
                remain_ = n;
                std::size_t m = seq_.size() - remain_;
                i_ = seq_.begin();
                while (m-- > 0)
                    i_++;
            }
        }

        std::size_t remain() const
        {
            return remain_;
        }

        template <typename Archive>
        void serialize(Archive & ar)
        {
            ar & seq_;
        }

    private:
        mutable Sequence & seq_;
        mutable iterator i_;
        mutable std::size_t remain_;
    };

    template <typename Sequence>
    const batch_sequence<Sequence> make_batch_sequence(Sequence & seq)
    {
        return batch_sequence<Sequence>(seq);
    }

} // namespace utils

#endif // BATCH_SEQUENCE_H
