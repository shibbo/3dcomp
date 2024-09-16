#pragma once

#include "gfx/gfx_Types.hpp"
#include "ui2d/ui2d_Types.hpp"
#include "util/util_IntrusiveList.hpp"
#include "util/util_MathTypes.hpp"

namespace nn {
    namespace gfx {
        class CommandBuffer;  // todo -- get rid of me later
    };

    namespace ui2d {
        namespace detail {
            class PaneBase {
            public:
                PaneBase();
                virtual ~PaneBase();

                nn::util::IntrusiveListNode mLink;  // 0x08
            };
        };  // namespace detail

        struct ResPane;
        class ResExtUserData;
        struct ResExtUserDataList;

        class AnimTransform;
        class AnimResource;
        class Material;
        class DrawInfo;
        class Pane;
        class CaptureTexture;

        typedef nn::util::IntrusiveList<Pane, nn::util::IntrusiveListMemberNodeTraits<detail::PaneBase, &detail::PaneBase::mLink, Pane>> PaneList;

        class Pane : public detail::PaneBase {
        public:
            NN_UI2D_RUNTIME_TYPEINFO_ROOT();

            Pane();

            struct CalculateContext {};

            typedef CalculateContext CalculateMtxContext;

            virtual ~Pane();
            virtual void Finalize(nn::gfx::Device*);
            virtual const nn::util::Unorm8x4 GetVertexColor(int) const;
            virtual void SetVertexColor(int, const nn::util::Unorm8x4&);
            virtual uint8_t GetColorElement(int) const;
            virtual void SetColorElement(int, uint8_t);
            virtual uint8_t GetVertexColorElement(int) const;
            virtual void SetVertexColorElement(int, uint8_t);
            virtual uint8_t GetMaterialCount() const;
            virtual Material* GetMaterial(int) const;
            virtual void GetSizeWithCaptureEffect(Size*) const;
            virtual void GetVertexPosWithCaptureEffect(util::Float2*) const;
            virtual float GetItalicSize() const;
            virtual Pane* FindPaneByName(const char*, bool recursive = true);
            virtual const Pane* FindPaneByName(const char*, bool recursive = true) const;
            virtual Material* FindMaterialByName(const char*, bool recursive = true);
            virtual const Material* FindMaterialByName(const char*, bool recursive = true) const;
            virtual void BindAnimation(AnimTransform*, bool recursive = true, bool enabled = true);
            virtual void UnbindAnimation(AnimTransform*, bool recursive = true);
            virtual void UnbindAnimationSelf(AnimTransform*);
            virtual void Calculate(DrawInfo&, CalculateMtxContext&, bool);
            virtual void Draw(DrawInfo&, nn::gfx::CommandBuffer&);
            virtual void DrawSelf(DrawInfo&, nn::gfx::CommandBuffer&);

            virtual void SetupPaneEffectSourceImageRenderState(nn::gfx::CommandBuffer&) const {}

            virtual void LoadMtx(DrawInfo&);
            virtual Pane* FindPaneByNameRecursive(const char*);
            virtual const Pane* FindPaneByNameRecursive(const char*) const;
            virtual Material* FindMaterialByNameRecursive(const char*);
            virtual const Material* FindMaterialByNameRecursive(const char*) const;

            void InitializeParams();
            void SetName(const char*);
            void SetUserData(const char*);

            Pane* mParent;
            PaneList mChildList;
            nn::util::Float3 mTranslate;
            nn::util::Float3 mRotate;
            nn::util::Float2 mScale;
            Size mSize;
            uint8_t mFlag;
            uint8_t mAlpha;
            uint8_t mGlobalAlpha;
            uint8_t mBasePosition;
            uint8_t mFlagEx;
            u8 pad[3];
            uint32_t mSystemFlags;
            u8 pad1[4];
            nn::util::MatrixT4x3fType mGlobalMtx;
            const nn::util::MatrixT4x3fType* mUserMtx;
            const ResExtUserDataList* mExtUserDataList;
            char mName[25];
            char mUserData[9];
        };
    };  // namespace ui2d
};  // namespace nn