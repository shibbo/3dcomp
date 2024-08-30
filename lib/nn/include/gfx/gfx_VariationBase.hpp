#pragma once

namespace nn {
    namespace gfx {
        enum LowLevelApi { LowLevelApi_Common = 0 };

        enum Version { Version_All = -1 };

        template <int Api>
        struct ApiType {
            static const int value = Api;
        };

        template <int Version>
        struct ApiVersion {
            static const int value = Version;
        };

        template <typename TType>
        struct DefaultVersion;

        template <typename TTarget>
        struct TargetVersion {
            typedef typename TTarget::Version Version;
        };

        template <typename TType, typename TVersion = typename TargetVersion<TType>::Version>
        struct ApiVariation {
            typedef TType Type;
            typedef TVersion Version;
            typedef ApiVariation<Type, Version> Variation;
        };

        template <typename TType>
        struct ApiTypeConfig {
            typedef TType Type;
            typedef typename DefaultVersion<Type>::Version DefaultVersion;
            typedef typename TargetVersion<Type>::Version TargetVersion;
            typedef ApiVariation<Type, TargetVersion> TargetVariation;
        };

        namespace detail {
            template <typename T, typename U>
            struct HasVariation;

            template <typename T>
            struct HasVariation<T, typename T::Variation> {
                typedef void Type;
            };

            template <typename T, int N = sizeof(T)>
            struct ExistsImpl {
                typedef void Type;
            };

            template <typename TApiType, typename X = void>
            struct TargetVariation {
                typedef typename ApiTypeConfig<TApiType>::TargetVariation Type;
            };

            template <typename TVariation>
            struct TargetVariation<
                TVariation,
                typename HasVariation<TVariation, typename TVariation::Variation>::Type> {
                typedef typename TVariation::Variation Type;
            };

            template <typename TInfoImpl, typename TInfo, typename X = void>
            struct TargetInfoImpl {
                typedef TInfo Type;
            };

            template <typename TInfoImpl, typename TInfo>
            struct TargetInfoImpl<TInfoImpl, TInfo, typename ExistsImpl<TInfoImpl>::Type> {
                typedef TInfoImpl Type;
            };
        };  // namespace detail
    };  // namespace gfx
};  // namespace nn