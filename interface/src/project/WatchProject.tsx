import React, { Component } from 'react';
import { Redirect, Switch, RouteComponentProps } from 'react-router-dom'

import { Tabs, Tab } from '@material-ui/core';

import { PROJECT_PATH } from '../api';
import { MenuAppBar } from '../components';
import { AuthenticatedRoute } from '../authentication';

import WatchController from './WatchBasicController'

import WatchInformation from './WatchInformation'
class WatchProject extends Component<RouteComponentProps> {

  handleTabChange = (event: React.ChangeEvent<{}>, path: string) => {
    this.props.history.push(path);
  };

  render() {
    return (
      <MenuAppBar sectionTitle="Demo Project">
        <Tabs value={this.props.match.url} onChange={this.handleTabChange} variant="fullWidth">
          <Tab value={`/${PROJECT_PATH}/watch/information`} label="Watch Information" />
          <Tab value={`/${PROJECT_PATH}/watch/controller`} label="Watch Controller" />
        </Tabs>
        <Switch>
          <AuthenticatedRoute exact path={`/${PROJECT_PATH}/watch/information`} component={WatchInformation} />
          <AuthenticatedRoute exact path={`/${PROJECT_PATH}/watch/controller`} component={WatchController} />
          <Redirect to={`/${PROJECT_PATH}/watch/information`} />
        </Switch>
      </MenuAppBar>
    )
  }

}

export default WatchProject;
