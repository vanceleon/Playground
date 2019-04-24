// import * as React from "react";

// export interface HelloProps { complier: string; framework: string; }

// export const Hello = ( props: HelloProps ) => <h1>Hello from {props.complier} and {props.framework}!</h1>;


import * as React from "react";

export interface HelloProps { complier: string; framework: string; }

// 'HelloProps' describes the shape of props.
// State is never set so we use the '{}' type.

export class Hello extends React.Component<HelloProps, {}> {
    render() {
        return <h1>Hello from {this.props.complier} and {this.props.framework}!</h1>;
    }
}