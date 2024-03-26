/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "globalcontext.h"

using namespace mu::context;
using namespace mu::project;
using namespace mu::async;

void GlobalContext::setCurrentProject(const IAudacityProjectPtr& project)
{
    if (m_currentProject == project) {
        return;
    }

    m_currentProject = project;
    m_currentProjectChanged.notify();
}

IAudacityProjectPtr GlobalContext::currentProject() const
{
    return m_currentProject;
}

Notification GlobalContext::currentProjectChanged() const
{
    return m_currentProjectChanged;
}

au::processing::ProcessingProjectPtr GlobalContext::currentProcessingProject() const
{
    return m_currentProject ? m_currentProject->processingProject() : nullptr;
}

mu::async::Notification GlobalContext::currentProcessingProjectChanged() const
{
    //! NOTE Same as main project
    return m_currentProjectChanged;
}
