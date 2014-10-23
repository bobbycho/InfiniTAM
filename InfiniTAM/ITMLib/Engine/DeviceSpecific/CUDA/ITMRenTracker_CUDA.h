// Copyright 2014 Isis Innovation Limited and the authors of InfiniTAM

#pragma once

#include "../../ITMRenTracker.h"

namespace ITMLib
{
	namespace Engine
	{
		template<class TVoxel, class TIndex>
		class ITMRenTracker_CUDA : public ITMRenTracker<TVoxel,TIndex>
		{
		private:
			float *f_host, *g_host, *h_host;
			float *f_device, *g_device, *h_device;
		protected:
			void F_oneLevel(float *f, Matrix4f invM);
			void G_oneLevel(float *gradient, float *hessian, Matrix4f invM) const;

			void UnprojectDepthToCam(ITMFloatImage *depth, ITMFloat4Image *upPtCloud, const Vector4f &intrinsic);

		public:
			ITMRenTracker_CUDA(Vector2i imgSize, int noHierarchyLevels, ITMLowLevelEngine *lowLevelEngine);
			~ITMRenTracker_CUDA(void);
		};
	}
}
