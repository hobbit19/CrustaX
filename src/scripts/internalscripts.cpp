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
