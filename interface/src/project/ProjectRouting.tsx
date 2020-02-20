import React, { Component } from 'react';
import { Redirect, Switch } from 'react-router';

import { PROJECT_PATH } from '../api';
import { AuthenticatedRoute } from '../authentication';

import WatchProject from './WatchProject';

class ProjectRouting extends Component {

  render() {
    return (
      <Switch>
        {
          /*
          * Add your project page routing below.
          */
        }
        
        <AuthenticatedRoute exact path={`/${PROJECT_PATH}/watch/*`} component={WatchProject} />
        {
          /*
          * The redirect below caters for the default project route and redirecting invalid paths.
          * The "to" property must match one of the routes above for this to work correctly.
          */
        }
        
        <Redirect to={`/${PROJECT_PATH}/watch/`} />
      </Switch>
    )
  }

}

export default ProjectRouting;
