/**************************************************************************
*   Copyright (C) 2013 by Robert Metsaranta                               *
*   therealestrob@gmail.com                                               *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/


#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QAction>
#include <QSettings>
#include <QByteArray>
#include <QMenu>

namespace DFM
{

typedef struct Config
{
    QString startPath, styleSheet;
    struct behaviour
    {
        bool hideTabBarWhenOnlyOneTab, systemIcons, devUsage, gayWindow, frame;
        int tabShape, tabRoundness, tabHeight, tabWidth;
        int view;
    } behaviour;
    struct views
    {
        QByteArray flowSize;
        bool showThumbs, singleClick;
        struct iconView
        {
            bool smoothScroll;
            int textWidth, iconSize;
        } iconView;
        struct detailsView
        {
            int rowPadding;
        } detailsView;
    } views;

    struct docks
    {
        int lock, infoArea;
    } docks;
} Config;


class Configuration : public QObject
{
public:
    static Configuration *instance();
    static inline void readConfig() { instance()->readConfiguration(); }
    static inline void writeConfig() { instance()->writeConfiguration(); }
    static QList<QAction *> customActions() { return instance()->ca(); }
    static QMenu *customActionsMenu() { return instance()->cam(); }
    static QList<QAction *> openWithActions(const QString &file);
    static QSettings *settings() { return instance()->stngs(); }
    static Config config;

protected:
    Configuration( QObject *parent = 0 );
    void readConfiguration();
    void writeConfiguration();
    inline QList<QAction *> ca() const { return m_customActions; }
    inline QSettings *stngs() { return m_settings; }
    inline QMenu *cam() { return &m_customActionsMenu; }

private:
    QSettings *m_settings;
    QList<QAction *> m_customActions;
    QMenu m_customActionsMenu;
};

}

#endif // CONFIG_H
