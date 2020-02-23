import React, { Component } from 'react';

import { CssBaseline } from '@material-ui/core';
import { MuiThemeProvider, createMuiTheme, StylesProvider, Theme } from '@material-ui/core/styles';
import { blueGrey, indigo, orange, red, green } from '@material-ui/core/colors';
import PropTypes from 'prop-types';
import getMuiTheme from 'material-ui/styles/getMuiTheme';
const theme = createMuiTheme({
  palette: {
    primary: indigo,
    secondary: blueGrey,
    info: {
      main: blueGrey[900]
    },
    warning: {
      main: orange[500]
    },
    error: {
      main: red[500]
    },
    success: {
      main: green[500]
    }
  },
});

const darktheme = createMuiTheme({
  palette: {
    type:"dark",
    primary: {
      main: '#222',
    },
    secondary: {
      main: '#666',
    },
    info: {
      main: blueGrey[900]
    },
    warning: {
      main: orange[500]
    },
    error: {
      main: red[500]
    },
    success: {
      main: green[500]
    }
  }
});

interface ThemeState {
  muiTheme: Theme;
}

interface ThemeProps {

}

export default class CustomMuiTheme extends Component<ThemeProps, ThemeState> {
  static childContextTypes = {
    darkTheme: PropTypes.func,
    lightTheme: PropTypes.func
  };

  constructor(props: any) {
    super(props);
    this.state = {
      muiTheme: theme
    };
  }

  getChildContext() {
    return {darkTheme: this.darkTheme,
    lightTheme: this.lightTheme};
  }

  darkTheme = () => {
    this.setState({
      muiTheme: darktheme
    })
  };
  
  lightTheme = () => {
    this.setState({
      muiTheme: theme
    })
  };
  render() {
    return (
      <StylesProvider>
        <MuiThemeProvider theme={this.state.muiTheme} >
          <CssBaseline />
          {this.props.children}
        </MuiThemeProvider>
      </StylesProvider>
    );
  }

}
