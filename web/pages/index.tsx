import { Box, Button, Flex, FormControl, FormErrorMessage, FormLabel, Heading, Input, Spacer, useColorMode, useColorModeValue } from "@chakra-ui/react"
import { Field, Form, Formik } from "formik";
import { Auth_LoginRequest } from "../proto/auth_pb";
import { Auth_ServiceClient } from "../proto/AuthServiceClientPb";

const IndexPage = () => {
  const {toggleColorMode} = useColorMode();
  const formBackground = useColorModeValue("gray.100", "gray.700");

  const validate_username = (value) => {
    let error;
    if (!value || value.length == 0) {
      error = 'Username is required';
    } else if (!String(value)
        .toLowerCase()
        .match(
        /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/
    )) {
        error = 'Email is invalid format';
    }

    return error;
  }

  const validate_password = (value) => {
    let error;
    if (!value || value.length == 0) {
      error = 'Password is required';
    }

    return error;
  }

  var client = new Auth_ServiceClient("http://localhost:80");

  return (
    <Flex height={"100vh"} alignItems="center" justifyContent={"center"}>
      <Flex direction={"column"} background={formBackground} p={12} rounded={6}>

        <Formik initialValues={{username: '', password: ''}}
          onSubmit={(values, actions) => {
            console.log(values);
            var request = new Auth_LoginRequest();
            request.setUsername(values.username);
            request.setPassword(values.password);

            client.login(request, {}, (err, res) => {
              console.log(res);
            });
        }}>
          {(props) => (
            <Form>
              <Heading mb={6}>Log in</Heading>
              <Field name='username' validate={validate_username}>
                {({field, form}) => (
                  <FormControl isInvalid={form.errors.username && form.touched.username}>
                    <FormLabel htmlFor='username'>Email</FormLabel>
                    <Input {...field} id='username' placeholder="email@gmail.com"/>
                    <FormErrorMessage>{form.errors.username}</FormErrorMessage>
                  </FormControl>
                )}
              </Field>
              <Box h={4}/>
              <Field name='password' validate={validate_password}>
                {({field, form}) => (
                  <FormControl isInvalid={form.errors.password && form.touched.password}>
                    <FormLabel htmlFor='password'>Password</FormLabel>
                    <Input {...field} id='password' placeholder="**********" type={"password"}/>
                    <FormErrorMessage>{form.errors.password}</FormErrorMessage>
                  </FormControl>
                )}
              </Field>
              <Box h={4}/>
              <Flex gap={2}>
                <Button colorScheme={'teal'} isLoading={props.isSubmitting} type={'submit'}>Log in</Button>
                <Spacer/>
                <Button onClick={toggleColorMode}>Toggle Color Mode</Button>
              </Flex>
            </Form>
          )}
        </Formik>
      </Flex>
    </Flex>
  )
}

export default IndexPage
