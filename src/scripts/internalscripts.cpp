/**
 * Crusta X - Qt webbrowser
 * Copyright (C) 2018 Anmol Gautam <anmol@crustabrowser.com>
 *
 * THIS FILE IS A PART OF CRUSTA X
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "internalscripts.h"

InternalScripts::InternalScripts()
{

}

QString InternalScripts::getFramework()
{
    QString src =
    "// @src - https://gist.github.com/leibovic/1017111\n"
    "function detectFrameworks(){"
        "var frameworks = [];"
        "if(!!window.React ||"
        "!!document.querySelector('[data-reactroot], [data-reactid]'))"
            "frameworks.push('React.js');"

        "if(!!window.angular ||"
        "!!document.querySelector('.ng-binding, [ng-app], [data-ng-app], [ng-controller], [data-ng-controller], [ng-repeat], [data-ng-repeat]') ||"
        "!!document.querySelector('script[src*=\"angular.js\"], script[src*=\"angular.min.js\"]'))"
            "frameworks.push('Angular.js');"

        "if(!!window.Backbone) frameworks.push('Backbone.js');"
        "if(!!window.Ember) frameworks.push('Ember.js');"
        "if(!!window.Vue) frameworks.push('Vue.js');"
        "if(!!window.Meteor) frameworks.push('Meteor.js');"
        "if(!!window.Zepto) frameworks.push('Zepto.js');"
        "if(!!window.jQuery) frameworks.push('jQuery.js');"
        "return frameworks;"
    "}"
    "detectFrameworks();";
    return src;
}
